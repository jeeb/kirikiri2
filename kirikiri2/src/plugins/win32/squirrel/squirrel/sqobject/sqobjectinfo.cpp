/*
 * copyright (c)2009 http://wamsoft.jp
 * zlib license
 */
#include "sqobjectinfo.h"
#include "sqobject.h"
#include "sqthread.h"
#include <string.h>

namespace sqobject {

// ���e����
void
ObjectInfo::clear()
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_release(gv,&obj);
	sq_resetobject(&obj);
}

// �X�^�b�N����擾
void
ObjectInfo::getStack(HSQUIRRELVM v, int idx)
{
	clear();
	HSQUIRRELVM gv = getGlobalVM();
	sq_move(gv, v, idx);
	sq_getstackobj(gv, -1, &obj);
	sq_addref(gv, &obj);
	sq_pop(gv, 1);
}

// �X�^�b�N�����Q�ƂƂ��Ď擾
void
ObjectInfo::getStackWeak(HSQUIRRELVM v, int idx)
{
	clear();
	HSQUIRRELVM gv = getGlobalVM();
	sq_weakref(v, idx);
	sq_move(gv, v, -1);
	sq_pop(v, 1);
	sq_getstackobj(gv, -1, &obj);
	sq_addref(gv, &obj);
	sq_pop(gv, 1);
}


// �R���X�g���N�^
ObjectInfo::ObjectInfo() {
	sq_resetobject(&obj);
}

// �R���X�g���N�^
ObjectInfo::ObjectInfo(HSQUIRRELVM v, int idx)
{
	sq_resetobject(&obj);
	HSQUIRRELVM gv = getGlobalVM();
	sq_move(gv, v, idx);
	sq_getstackobj(gv, -1, &obj);
	sq_addref(gv, &obj);
	sq_pop(gv, 1);
}

// �R�s�[�R���X�g���N�^
ObjectInfo::ObjectInfo(const ObjectInfo &orig)
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_resetobject(&obj);
	obj = orig.obj;
	sq_addref(gv, &obj);
}

// ���
ObjectInfo& ObjectInfo::operator =(const ObjectInfo &orig)
{
	HSQUIRRELVM gv = getGlobalVM();
	clear();
	obj = orig.obj;
	sq_addref(gv, &obj);
	return *this;
}

// �f�X�g���N�^
ObjectInfo::~ObjectInfo()
{
	clear();
}

// null���H
bool
ObjectInfo::isNull() const
{
	if (sq_isweakref(obj)) {
		HSQUIRRELVM gv = getGlobalVM();
		sq_pushobject(gv, obj);
		sq_getweakrefval(gv, -1);
		bool ret = sq_gettype(gv, -1) == OT_NULL;
		sq_pop(gv, 2);
		return ret;
	}
	return sq_isnull(obj);
}

// �����X���b�h���H
bool
ObjectInfo::isSameThread(const HSQUIRRELVM v) const
{
	return sq_isthread(obj) && obj._unVal.pThread == v;
}

// �X���b�h���擾
ObjectInfo::operator HSQUIRRELVM() const
{
	HSQUIRRELVM vm = sq_isthread(obj) ? obj._unVal.pThread : NULL;
	return vm;
}
	
// �I�u�W�F�N�g��PUSH
void
ObjectInfo::push(HSQUIRRELVM v) const
{
    if (sq_isweakref(obj)) {
		sq_pushobject(v, obj);
		sq_getweakrefval(v, -1);
		sq_remove(v, -2);
	} else {
		sq_pushobject(v, obj);
	}
}

// ---------------------------------------------------
// delegate �����p
// ---------------------------------------------------

// delegate �Ƃ��ċ@�\���邩�ǂ���
bool
ObjectInfo::isDelegate() const
{
	return (sq_isinstance(obj) || sq_istable(obj));
}

// bindenv �����邩�ǂ���
bool
ObjectInfo::isBindDelegate() const
{
	return (sq_isinstance(obj));
}

// ---------------------------------------------------
// �f�[�^�擾
// ---------------------------------------------------

const SQChar *
ObjectInfo::getString()
{
	if (sq_isstring(obj)) {
		HSQUIRRELVM gv = getGlobalVM();
		const SQChar *mystr;
		sq_pushobject(gv, obj);
		sq_getstring(gv, -1, &mystr);
		sq_pop(gv, 1);
		return mystr;
	}
	return NULL;
}

// ---------------------------------------------------
// wait�����p���\�b�h
// ---------------------------------------------------

bool
ObjectInfo::isSameString(const SQChar *str) const
{
	if (str && sq_isstring(obj)) {
		HSQUIRRELVM gv = getGlobalVM();
		const SQChar *mystr;
		sq_pushobject(gv, obj);
		sq_getstring(gv, -1, &mystr);
		sq_pop(gv, 1);
		return mystr && scstrcmp(str, mystr) == 0;
	}
	return false;
}

// ---------------------------------------------------
// �z�񏈗��p���\�b�h
// ---------------------------------------------------


/// �z��Ƃ��ď�����
void
ObjectInfo::initArray(int size)
{
	clear();
	HSQUIRRELVM gv = getGlobalVM();
	sq_newarray(gv, size);
	sq_getstackobj(gv, -1, &obj);
	sq_addref(gv, &obj);
	sq_pop(gv, 1);
}

/// �z��ɒl��ǉ�
void ObjectInfo::append(HSQUIRRELVM v, int idx)
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	sq_move(gv, v, idx);
	sq_arrayappend(gv, -2);
	sq_pop(gv,1);
}

/// �z��ɒl��ǉ�
template<typename T>
void ObjectInfo::append(T value)
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	pushValue(gv, value);
	sq_arrayappend(gv, -2);
	sq_pop(gv,1);
}

/// �z��ɒl��}��
template<typename T>
void ObjectInfo::insert(int index, T value)
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	pushValue(gv, value);
	sq_arrayinsert(gv, -2, index);
	sq_pop(gv,1);
}

/// �z��ɒl���i�[
template<typename T>
void ObjectInfo::set(int index, T value)
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	sq_pushinteger(gv, index);
	pushValue(gv, value);
	sq_set(gv, -3);
	sq_pop(gv,1);
}

/// �z��̒���
int
ObjectInfo::len() const
{
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	int ret = sq_getsize(gv,-1);
	sq_pop(gv,1);
	return ret;
}

/**
 * �z��̓��e��S��PUSH
 * @param v squirrelVM
 * @return push ������
 */
int
ObjectInfo::pushArray(HSQUIRRELVM v) const
{
	if (!isArray()) {
		return 0;
	}
	HSQUIRRELVM gv = getGlobalVM();
	sq_pushobject(gv, obj);
	int len = sq_getsize(gv,-1);
	for (int i=0;i<len;i++) {
		sq_pushinteger(gv, i);
		sq_get(gv, -2);
		sq_move(v, gv, -1);
		sq_pop(gv, 1);
	}
	sq_pop(gv,1);
	return len;
}

};