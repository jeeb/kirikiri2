#include <windows.h>
#include "tp_stub.h"

#define TVP_MSG_DECL(name, text) const tjs_char* name = TJS_W(text);

TVP_MSG_DECL(TVPFaildToCreateDirect3D,                                        "Faild to create Direct3D9.")
TVP_MSG_DECL(TVPFaildToDecideBackbufferFormat,                                "Faild to decide backbuffer format.")
TVP_MSG_DECL(TVPFaildToCreateDirect3DDevice,                                  "Faild to create Direct3D9 Device.")
TVP_MSG_DECL(TVPFaildToSetViewport,                                           "Faild to set viewport.")
TVP_MSG_DECL(TVPFaildToSetRenderState,                                        "Faild to set render state.")
TVP_MSG_DECL(TVPWarningImageSizeTooLargeMayBeCannotCreateTexture,             "warning : Image size too large. May be cannot create texture.")
TVP_MSG_DECL(TVPUsePowerOfTwoSurface,                                         "Use power of two surface.")
TVP_MSG_DECL(TVPCannotAllocateD3DOffScreenSurface,                            "Cannot allocate D3D off-screen surface/HR=%1")
TVP_MSG_DECL(TVPBasicDrawDeviceFailedToCreateDirect3DDevices,                 "DrawDeviceZ: Failed to create Direct3D devices: %1")
TVP_MSG_DECL(TVPBasicDrawDeviceFailedToCreateDirect3DDevicesUnknownReason,    "DrawDeviceZ: Failed to create Direct3D devices: unknown reason")
TVP_MSG_DECL(TVPBasicDrawDeviceTextureHasAlreadyBeenLocked,                   "DrawDeviceZ: Texture has already been locked (StartBitmapCompletion() has been called twice without EndBitmapCompletion()), unlocking the texture.")
TVP_MSG_DECL(TVPInternalErrorResult,                                          "DrawDeviceZ: Internal error/HR=%1")
TVP_MSG_DECL(TVPBasicDrawDeviceInfPolygonDrawingFailed,                       "DrawDeviceZ: (inf) Polygon drawing failed/HR=%1")
TVP_MSG_DECL(TVPBasicDrawDeviceInfDirect3DDevicePresentFailed,                "DrawDeviceZ: (inf) IDirect3DDevice::Present failed/HR=%1")

TVP_MSG_DECL(TVPBasicDrawDeviceFailedToCreateDirect3DDevice,                  "DrawDeviceZ: Failed to create Direct3D Device: %1")
TVP_MSG_DECL(TVPBasicDrawDeviceFailedToCreateDirect3DDeviceUnknownReason,     "DrawDeviceZ: Failed to create Direct3D Device: unknown reason")

TVP_MSG_DECL(TVPBasicDrawDeviceDoesNotSupporteLayerManagerMoreThanOne,        "DrawDeviceZ does not support layer manager more than 1")

TVP_MSG_DECL(TVPInfoDirect3D,                                                 "(info) Loading Direct3D ...")
TVP_MSG_DECL(TVPCannotLoadD3DDLL,                                             "Cannot load d3d9.dll")
TVP_MSG_DECL(TVPNotFoundDirect3DCreate,                                       "Missing Direct3DCreate9 in d3d9.dll")

TVP_MSG_DECL(TVPCannotInitDirect3D,                                           "Cannot initialize Direct3D : %1")

TVP_MSG_DECL(TVPD3dErrDeviceLost,                                             "D3D : The device has been lost but cannot be reset at this time.")
TVP_MSG_DECL(TVPD3dErrDriverIinternalError,                                   "D3D : Internal driver error. Applications should destroy and recreate the device when receiving this error. ")
TVP_MSG_DECL(TVPD3dErrInvalidCall,                                            "D3D : The method call is invalid. For example, a method's parameter may not be a valid pointer.")
TVP_MSG_DECL(TVPD3dErrOutOfVideoMemory,                                       "D3D : Direct3D does not have enough display memory to perform the operation. ")
TVP_MSG_DECL(TVPD3dErrOutOfMemory,                                            "D3D : Direct3D could not allocate sufficient memory to complete the call.")
TVP_MSG_DECL(TVPD3dErrWrongTextureFormat,                                     "D3D : The pixel format of the texture surface is not valid.")
TVP_MSG_DECL(TVPD3dErrUnsuportedColorOperation,                               "D3D : The device does not support a specified texture-blending operation for color values.")
TVP_MSG_DECL(TVPD3dErrUnsuportedColorArg,                                     "D3D : The device does not support a specified texture-blending argument for color values.")
TVP_MSG_DECL(TVPD3dErrUnsuportedAalphtOperation,                              "D3D : The device does not support a specified texture-blending operation for the alpha channel.")
TVP_MSG_DECL(TVPD3dErrUnsuportedAlphaArg,                                     "D3D : The device does not support a specified texture-blending argument for the alpha channel.")
TVP_MSG_DECL(TVPD3dErrTooManyOperations,                                      "D3D : The application is requesting more texture-filtering operations than the device supports.")
TVP_MSG_DECL(TVPD3dErrConflictioningTextureFilter,                            "D3D : The current texture filters cannot be used together.")
TVP_MSG_DECL(TVPD3dErrUnsuportedFactorValue,                                  "D3D : The device does not support the specified texture factor value. Not used; provided only to support older drivers.")
TVP_MSG_DECL(TVPD3dErrConflictioningRenderState,                              "D3D : The currently set render states cannot be used together.")
TVP_MSG_DECL(TVPD3dErrUnsupportedTextureFilter,                               "D3D : The device does not support the specified texture filter.")
TVP_MSG_DECL(TVPD3dErrConflictioningTexturePalette,                           "D3D : The current textures cannot be used simultaneously.")
TVP_MSG_DECL(TVPD3dErrNotFound,                                               "D3D : The requested item was not found.")
TVP_MSG_DECL(TVPD3dErrMoreData,                                               "D3D : There is more data available than the specified buffer size can hold.")
TVP_MSG_DECL(TVPD3dErrDeviceNotReset,                                         "D3D : The device has been lost but can be reset at this time.")
TVP_MSG_DECL(TVPD3dErrNotAvailable,                                           "D3D : This device does not support the queried technique.")
TVP_MSG_DECL(TVPD3dErrInvalidDevice,                                          "D3D : The requested device type is not valid.")
TVP_MSG_DECL(TVPD3dErrDriverInvalidCall,                                      "D3D : Not used.")
TVP_MSG_DECL(TVPD3dErrWasStillDrawing,                                        "D3D : The previous blit operation that is transferring information to or from this surface is incomplete.")
TVP_MSG_DECL(TVPD3dErrDeviceHung,                                             "D3D : The device that returned this code caused the hardware adapter to be reset by the OS.")
TVP_MSG_DECL(TVPD3dErrUnsupportedOverlay,                                     "D3D : The device does not support overlay for the specified size or display mode. ")
TVP_MSG_DECL(TVPD3dErrUnsupportedOverlayFormat,                               "D3D : The device does not support overlay for the specified surface format. ")
TVP_MSG_DECL(TVPD3dErrCannotProtectContent,                                   "D3D : The specified content cannot be protected.")
TVP_MSG_DECL(TVPD3dErrUnsupportedCrypto,                                      "D3D : The specified cryptographic algorithm is not supported.")
TVP_MSG_DECL(TVPD3dErrPresentStatisticsDisJoint,                              "D3D : The present statistics have no orderly sequence.")
TVP_MSG_DECL(TVPD3dErrDeviceRemoved,                                          "D3D : The hardware adapter has been removed.")
TVP_MSG_DECL(TVPD3dOkNoAutoGen,                                               "D3D : This is a success code. However, the autogeneration of mipmaps is not supported for this format.")
TVP_MSG_DECL(TVPD3dErrFail,                                                   "D3D : An undetermined error occurred inside the Direct3D subsystem.")
TVP_MSG_DECL(TVPD3dErrInvalidArg,                                             "D3D : An invalid parameter was passed to the returning function.")
TVP_MSG_DECL(TVPD3dUnknownError,                                              "D3D : Unknown error.")

