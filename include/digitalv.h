/*
 * Copyright (C) 1999 Eric Pouech
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_DIGITALV_H
#define __WINE_DIGITALV_H

/*
 * Wine Digital Video extensions
 */

#pragma pack(push,1)

#ifdef __cplusplus
extern "C" {
#endif

#define MCI_TEST                            __MSABI_LONG(0x00000020)

/* Message values */

#define MCI_CAPTURE                         0x0870
#define MCI_MONITOR                         0x0871
#define MCI_RESERVE                         0x0872
#define MCI_SETAUDIO                        0x0873
#define MCI_SIGNAL                          0x0875
#define MCI_SETVIDEO                        0x0876
#define MCI_QUALITY                         0x0877
#define MCI_LIST                            0x0878
#define MCI_UNDO                            0x0879
#define MCI_CONFIGURE                       0x087A
#define MCI_RESTORE                         0x087B

/* Return and string constant values */

#define MCI_ON   1
#define MCI_OFF  0

#define MCI_DGV_FILE_MODE_SAVING            0x0001
#define MCI_DGV_FILE_MODE_LOADING           0x0002
#define MCI_DGV_FILE_MODE_EDITING           0x0003
#define MCI_DGV_FILE_MODE_IDLE              0x0004

/* These identifiers are used only by device drivers */

#define MCI_ON_S                            __MSABI_LONG(0x00008000)
#define MCI_OFF_S                           __MSABI_LONG(0x00008001)
#define MCI_DGV_FILE_S                      __MSABI_LONG(0x00008002)
#define MCI_DGV_INPUT_S                     __MSABI_LONG(0x00008003)

#define MCI_DGV_FILE_MODE_SAVING_S          __MSABI_LONG(0x00008004)
#define MCI_DGV_FILE_MODE_LOADING_S         __MSABI_LONG(0x00008005)
#define MCI_DGV_FILE_MODE_EDITING_S         __MSABI_LONG(0x00008006)
#define MCI_DGV_FILE_MODE_IDLE_S            __MSABI_LONG(0x00008007)

#define MCI_DGV_SETVIDEO_SRC_NTSC_S         __MSABI_LONG(0x00008010)
#define MCI_DGV_SETVIDEO_SRC_RGB_S          __MSABI_LONG(0x00008011)
#define MCI_DGV_SETVIDEO_SRC_SVIDEO_S       __MSABI_LONG(0x00008012)
#define MCI_DGV_SETVIDEO_SRC_PAL_S          __MSABI_LONG(0x00008013)
#define MCI_DGV_SETVIDEO_SRC_SECAM_S        __MSABI_LONG(0x00008014)
#define MCI_DGV_SETVIDEO_SRC_GENERIC_S      __MSABI_LONG(0x00008015)

#define MCI_DGV_SETAUDIO_SRC_LEFT_S         __MSABI_LONG(0x00008020)
#define MCI_DGV_SETAUDIO_SRC_RIGHT_S        __MSABI_LONG(0x00008021)
#define MCI_DGV_SETAUDIO_SRC_AVERAGE_S      __MSABI_LONG(0x00008022)
#define MCI_DGV_SETAUDIO_SRC_STEREO_S       __MSABI_LONG(0x00008023)

/* Window message for signal notification */

#ifndef MM_MCISIGNAL
#define MM_MCISIGNAL                        0x3CB
#endif

/* error values */

#define MCIERR_DGV_DEVICE_LIMIT             (MCIERR_CUSTOM_DRIVER_BASE+0)
#define MCIERR_DGV_IOERR                    (MCIERR_CUSTOM_DRIVER_BASE+1)
#define MCIERR_DGV_WORKSPACE_EMPTY          (MCIERR_CUSTOM_DRIVER_BASE+2)
#define MCIERR_DGV_DISK_FULL                (MCIERR_CUSTOM_DRIVER_BASE+3)
#define MCIERR_DGV_DEVICE_MEMORY_FULL       (MCIERR_CUSTOM_DRIVER_BASE+4)
#define MCIERR_DGV_BAD_CLIPBOARD_RANGE      (MCIERR_CUSTOM_DRIVER_BASE+5)

/* defines for monitor methods */

#define MCI_DGV_METHOD_PRE                  __MSABI_LONG(0x0000a000)
#define MCI_DGV_METHOD_POST                 __MSABI_LONG(0x0000a001)
#define MCI_DGV_METHOD_DIRECT               __MSABI_LONG(0x0000a002)

/* defines for known file formats */

#define MCI_DGV_FF_AVSS                     __MSABI_LONG(0x00004000)
#define MCI_DGV_FF_AVI                      __MSABI_LONG(0x00004001)
#define MCI_DGV_FF_DIB                      __MSABI_LONG(0x00004002)
#define MCI_DGV_FF_RDIB                     __MSABI_LONG(0x00004003)
#define MCI_DGV_FF_JPEG                     __MSABI_LONG(0x00004004)
#define MCI_DGV_FF_RJPEG                    __MSABI_LONG(0x00004005)
#define MCI_DGV_FF_JFIF                     __MSABI_LONG(0x00004006)
#define MCI_DGV_FF_MPEG                     __MSABI_LONG(0x00004007)

/* values for dwItem field of MCI_CAPABILITY_PARMS structure */

#define MCI_DGV_GETDEVCAPS_CAN_LOCK         __MSABI_LONG(0x00004000)
#define MCI_DGV_GETDEVCAPS_CAN_STRETCH      __MSABI_LONG(0x00004001)
#define MCI_DGV_GETDEVCAPS_CAN_FREEZE       __MSABI_LONG(0x00004002)
#define MCI_DGV_GETDEVCAPS_MAX_WINDOWS      __MSABI_LONG(0x00004003)
#define MCI_DGV_GETDEVCAPS_CAN_REVERSE      __MSABI_LONG(0x00004004)
#define MCI_DGV_GETDEVCAPS_HAS_STILL        __MSABI_LONG(0x00004005)
#define MCI_DGV_GETDEVCAPS_PALETTES         __MSABI_LONG(0x00004006)
#define MCI_DGV_GETDEVCAPS_CAN_STR_IN       __MSABI_LONG(0x00004008)
#define MCI_DGV_GETDEVCAPS_CAN_TEST         __MSABI_LONG(0x00004009)
#define MCI_DGV_GETDEVCAPS_MAXIMUM_RATE     __MSABI_LONG(0x0000400a)
#define MCI_DGV_GETDEVCAPS_MINIMUM_RATE     __MSABI_LONG(0x0000400b)

/* flags for dwFlags parameter of MCI_CAPTURE command message */

#define MCI_DGV_CAPTURE_AS                  __MSABI_LONG(0x00010000)
#define MCI_DGV_CAPTURE_AT                  __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_COPY command message */

#define MCI_DGV_COPY_AT                     __MSABI_LONG(0x00010000)
#define MCI_DGV_COPY_AUDIO_STREAM           __MSABI_LONG(0x00020000)
#define MCI_DGV_COPY_VIDEO_STREAM           __MSABI_LONG(0x00040000)

/* flags for dwFlags parameter of MCI_CUE command message */

#define MCI_DGV_CUE_INPUT                   __MSABI_LONG(0x00010000)
#define MCI_DGV_CUE_OUTPUT                  __MSABI_LONG(0x00020000)
#define MCI_DGV_CUE_NOSHOW                  __MSABI_LONG(0x00040000)

/* flags for dwFlags parameter of MCI_CUT command message */

#define MCI_DGV_CUT_AT                      __MSABI_LONG(0x00010000)
#define MCI_DGV_CUT_AUDIO_STREAM            __MSABI_LONG(0x00020000)
#define MCI_DGV_CUT_VIDEO_STREAM            __MSABI_LONG(0x00040000)

/* flags for dwFlags parameter of MCI_DELETE command message */

#define MCI_DGV_DELETE_AT                   __MSABI_LONG(0x00010000)
#define MCI_DGV_DELETE_AUDIO_STREAM         __MSABI_LONG(0x00020000)
#define MCI_DGV_DELETE_VIDEO_STREAM         __MSABI_LONG(0x00040000)

/* flags for dwFlags parameter of MCI_FREEZE command message */

#define MCI_DGV_FREEZE_AT                   __MSABI_LONG(0x00010000)
#define MCI_DGV_FREEZE_OUTSIDE              __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_INFO command message */

#define MCI_DGV_INFO_TEXT                   __MSABI_LONG(0x00010000)
#define MCI_DGV_INFO_ITEM                   __MSABI_LONG(0x00020000)

/* values for dwItem field of MCI_DGV_INFO_PARMS structure */

#define MCI_INFO_VERSION                    __MSABI_LONG(0x00000400)

#define MCI_DGV_INFO_USAGE                  __MSABI_LONG(0x00004000)
#define MCI_DGV_INFO_AUDIO_QUALITY          __MSABI_LONG(0x00004001)
#define MCI_DGV_INFO_STILL_QUALITY          __MSABI_LONG(0x00004002)
#define MCI_DGV_INFO_VIDEO_QUALITY          __MSABI_LONG(0x00004003)
#define MCI_DGV_INFO_AUDIO_ALG              __MSABI_LONG(0x00004004)
#define MCI_DGV_INFO_STILL_ALG              __MSABI_LONG(0x00004005)
#define MCI_DGV_INFO_VIDEO_ALG              __MSABI_LONG(0x00004006)

/* flags for dwFlags parameter of MCI_LIST command message */

#define MCI_DGV_LIST_ITEM                   __MSABI_LONG(0x00010000)
#define MCI_DGV_LIST_COUNT                  __MSABI_LONG(0x00020000)
#define MCI_DGV_LIST_NUMBER                 __MSABI_LONG(0x00040000)
#define MCI_DGV_LIST_ALG                    __MSABI_LONG(0x00080000)

/* values for dwItem field of MCI_DGV_LIST_PARMS structure */

#define MCI_DGV_LIST_AUDIO_ALG              __MSABI_LONG(0x00004000)
#define MCI_DGV_LIST_AUDIO_QUALITY          __MSABI_LONG(0x00004001)
#define MCI_DGV_LIST_AUDIO_STREAM           __MSABI_LONG(0x00004002)
#define MCI_DGV_LIST_STILL_ALG              __MSABI_LONG(0x00004003)
#define MCI_DGV_LIST_STILL_QUALITY          __MSABI_LONG(0x00004004)
#define MCI_DGV_LIST_VIDEO_ALG              __MSABI_LONG(0x00004005)
#define MCI_DGV_LIST_VIDEO_QUALITY          __MSABI_LONG(0x00004006)
#define MCI_DGV_LIST_VIDEO_STREAM           __MSABI_LONG(0x00004007)
#define MCI_DGV_LIST_VIDEO_SOURCE           __MSABI_LONG(0x00004008)


/* flags for dwFlags parameter of MCI_MONITOR command message */

#define MCI_DGV_MONITOR_METHOD              __MSABI_LONG(0x00010000)
#define MCI_DGV_MONITOR_SOURCE              __MSABI_LONG(0x00020000)

/* values for dwSource parameter of the MCI_DGV_MONITOR_PARMS structure */

#define MCI_DGV_MONITOR_INPUT               __MSABI_LONG(0x00004000)
#define MCI_DGV_MONITOR_FILE                __MSABI_LONG(0x00004001)

/* flags for dwFlags parameter of MCI_OPEN command message */

#define MCI_DGV_OPEN_WS                     __MSABI_LONG(0x00010000)
#define MCI_DGV_OPEN_PARENT                 __MSABI_LONG(0x00020000)
#define MCI_DGV_OPEN_NOSTATIC               __MSABI_LONG(0x00040000)
#define MCI_DGV_OPEN_16BIT                  __MSABI_LONG(0x00080000)
#define MCI_DGV_OPEN_32BIT                  __MSABI_LONG(0x00100000)

/* flags for dwFlags parameter of MCI_PASTE command message */

#define MCI_DGV_PASTE_AT                    __MSABI_LONG(0x00010000)
#define MCI_DGV_PASTE_AUDIO_STREAM          __MSABI_LONG(0x00020000)
#define MCI_DGV_PASTE_VIDEO_STREAM          __MSABI_LONG(0x00040000)
#define MCI_DGV_PASTE_INSERT                __MSABI_LONG(0x00080000)
#define MCI_DGV_PASTE_OVERWRITE             __MSABI_LONG(0x00100000)

/* flags for dwFlags parameter of MCI_PLAY command message */

#define MCI_DGV_PLAY_REPEAT                 __MSABI_LONG(0x00010000)
#define MCI_DGV_PLAY_REVERSE                __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_PUT command message */

#define MCI_DGV_RECT                        __MSABI_LONG(0x00010000)
#define MCI_DGV_PUT_SOURCE                  __MSABI_LONG(0x00020000)
#define MCI_DGV_PUT_DESTINATION             __MSABI_LONG(0x00040000)
#define MCI_DGV_PUT_FRAME                   __MSABI_LONG(0x00080000)
#define MCI_DGV_PUT_VIDEO                   __MSABI_LONG(0x00100000)
#define MCI_DGV_PUT_WINDOW                  __MSABI_LONG(0x00200000)
#define MCI_DGV_PUT_CLIENT                  __MSABI_LONG(0x00400000)

/* flags for dwFlags parameter of MCI_QUALITY command message */

#define MCI_QUALITY_ITEM                    __MSABI_LONG(0x00010000)
#define MCI_QUALITY_NAME                    __MSABI_LONG(0x00020000)
#define MCI_QUALITY_ALG                     __MSABI_LONG(0x00040000)
#define MCI_QUALITY_DIALOG                  __MSABI_LONG(0x00080000)
#define MCI_QUALITY_HANDLE                  __MSABI_LONG(0x00100000)

/* values for dwItem field of MCI_QUALITY_PARMS structure */

#define MCI_QUALITY_ITEM_AUDIO              __MSABI_LONG(0x00004000)
#define MCI_QUALITY_ITEM_STILL              __MSABI_LONG(0x00004001)
#define MCI_QUALITY_ITEM_VIDEO              __MSABI_LONG(0x00004002)

/* flags for dwFlags parameter of MCI_REALIZE command message */

#define MCI_DGV_REALIZE_NORM                __MSABI_LONG(0x00010000)
#define MCI_DGV_REALIZE_BKGD                __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_RECORD command message */

#define MCI_DGV_RECORD_HOLD                 __MSABI_LONG(0x00020000)
#define MCI_DGV_RECORD_AUDIO_STREAM         __MSABI_LONG(0x00040000)
#define MCI_DGV_RECORD_VIDEO_STREAM         __MSABI_LONG(0x00080000)

/* flags for dwFlags parameters of MCI_RESERVE command message */

#define MCI_DGV_RESERVE_IN                  __MSABI_LONG(0x00010000)
#define MCI_DGV_RESERVE_SIZE                __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_RESTORE command message */

#define MCI_DGV_RESTORE_FROM                __MSABI_LONG(0x00010000)
#define MCI_DGV_RESTORE_AT                  __MSABI_LONG(0x00020000)

/* flags for dwFlags parameters of MCI_SAVE command message */

#define MCI_DGV_SAVE_ABORT                  __MSABI_LONG(0x00020000)
#define MCI_DGV_SAVE_KEEPRESERVE            __MSABI_LONG(0x00040000)

/* flags for dwFlags parameters of MCI_SET command message */

#define MCI_DGV_SET_SEEK_EXACTLY            __MSABI_LONG(0x00010000)
#define MCI_DGV_SET_SPEED                   __MSABI_LONG(0x00020000)
#define MCI_DGV_SET_STILL                   __MSABI_LONG(0x00040000)
#define MCI_DGV_SET_FILEFORMAT              __MSABI_LONG(0x00080000)

/* flags for the dwFlags parameter of MCI_SETAUDIO command message */

#define MCI_DGV_SETAUDIO_OVER               __MSABI_LONG(0x00010000)
#define MCI_DGV_SETAUDIO_CLOCKTIME          __MSABI_LONG(0x00020000)
#define MCI_DGV_SETAUDIO_ALG                __MSABI_LONG(0x00040000)
#define MCI_DGV_SETAUDIO_QUALITY            __MSABI_LONG(0x00080000)
#define MCI_DGV_SETAUDIO_RECORD             __MSABI_LONG(0x00100000)
#define MCI_DGV_SETAUDIO_LEFT               __MSABI_LONG(0x00200000)
#define MCI_DGV_SETAUDIO_RIGHT              __MSABI_LONG(0x00400000)
#define MCI_DGV_SETAUDIO_ITEM               __MSABI_LONG(0x00800000)
#define MCI_DGV_SETAUDIO_VALUE              __MSABI_LONG(0x01000000)
#define MCI_DGV_SETAUDIO_INPUT              __MSABI_LONG(0x02000000)
#define MCI_DGV_SETAUDIO_OUTPUT             __MSABI_LONG(0x04000000)

/* values for the dwItem parameter of MCI_DGV_SETAUDIO_PARMS */

#define MCI_DGV_SETAUDIO_TREBLE             __MSABI_LONG(0x00004000)
#define MCI_DGV_SETAUDIO_BASS               __MSABI_LONG(0x00004001)
#define MCI_DGV_SETAUDIO_VOLUME             __MSABI_LONG(0x00004002)
#define MCI_DGV_SETAUDIO_STREAM             __MSABI_LONG(0x00004003)
#define MCI_DGV_SETAUDIO_SOURCE             __MSABI_LONG(0x00004004)
#define MCI_DGV_SETAUDIO_SAMPLESPERSEC      __MSABI_LONG(0x00004005)
#define MCI_DGV_SETAUDIO_AVGBYTESPERSEC     __MSABI_LONG(0x00004006)
#define MCI_DGV_SETAUDIO_BLOCKALIGN         __MSABI_LONG(0x00004007)
#define MCI_DGV_SETAUDIO_BITSPERSAMPLE      __MSABI_LONG(0x00004008)

/* values for the dwValue parameter of MCI_DGV_SETAUDIO_PARMS
   used with MCI_DGV_SETAUDIO_SOURCE */

#define MCI_DGV_SETAUDIO_SOURCE_STEREO      __MSABI_LONG(0x00000000)
#define MCI_DGV_SETAUDIO_SOURCE_LEFT        __MSABI_LONG(0x00000001)
#define MCI_DGV_SETAUDIO_SOURCE_RIGHT       __MSABI_LONG(0x00000002)
#define MCI_DGV_SETAUDIO_SOURCE_AVERAGE     __MSABI_LONG(0x00004000)

/* flags for the dwFlags parameter of MCI_SETVIDEO command */

#define MCI_DGV_SETVIDEO_QUALITY            __MSABI_LONG(0x00010000)
#define MCI_DGV_SETVIDEO_ALG                __MSABI_LONG(0x00020000)
#define MCI_DGV_SETVIDEO_CLOCKTIME          __MSABI_LONG(0x00040000)
#define MCI_DGV_SETVIDEO_SRC_NUMBER         __MSABI_LONG(0x00080000)
#define MCI_DGV_SETVIDEO_ITEM               __MSABI_LONG(0x00100000)
#define MCI_DGV_SETVIDEO_OVER               __MSABI_LONG(0x00200000)
#define MCI_DGV_SETVIDEO_RECORD             __MSABI_LONG(0x00400000)
#define MCI_DGV_SETVIDEO_STILL              __MSABI_LONG(0x00800000)
#define MCI_DGV_SETVIDEO_VALUE              __MSABI_LONG(0x01000000)
#define MCI_DGV_SETVIDEO_INPUT              __MSABI_LONG(0x02000000)
#define MCI_DGV_SETVIDEO_OUTPUT             __MSABI_LONG(0x04000000)

/* values for the dwTo field of MCI_SETVIDEO_PARMS
   used with MCI_DGV_SETVIDEO_SOURCE */

#define MCI_DGV_SETVIDEO_SRC_NTSC           __MSABI_LONG(0x00004000)
#define MCI_DGV_SETVIDEO_SRC_RGB            __MSABI_LONG(0x00004001)
#define MCI_DGV_SETVIDEO_SRC_SVIDEO         __MSABI_LONG(0x00004002)
#define MCI_DGV_SETVIDEO_SRC_PAL            __MSABI_LONG(0x00004003)
#define MCI_DGV_SETVIDEO_SRC_SECAM          __MSABI_LONG(0x00004004)
#define MCI_DGV_SETVIDEO_SRC_GENERIC        __MSABI_LONG(0x00004005)

/* values for the dwItem field of MCI_SETVIDEO_PARMS */

#define MCI_DGV_SETVIDEO_BRIGHTNESS         __MSABI_LONG(0x00004000)
#define MCI_DGV_SETVIDEO_COLOR              __MSABI_LONG(0x00004001)
#define MCI_DGV_SETVIDEO_CONTRAST           __MSABI_LONG(0x00004002)
#define MCI_DGV_SETVIDEO_TINT               __MSABI_LONG(0x00004003)
#define MCI_DGV_SETVIDEO_SHARPNESS          __MSABI_LONG(0x00004004)
#define MCI_DGV_SETVIDEO_GAMMA              __MSABI_LONG(0x00004005)
#define MCI_DGV_SETVIDEO_STREAM             __MSABI_LONG(0x00004006)
#define MCI_DGV_SETVIDEO_PALHANDLE          __MSABI_LONG(0x00004007)
#define MCI_DGV_SETVIDEO_FRAME_RATE         __MSABI_LONG(0x00004008)
#define MCI_DGV_SETVIDEO_SOURCE             __MSABI_LONG(0x00004009)
#define MCI_DGV_SETVIDEO_KEY_INDEX          __MSABI_LONG(0x0000400a)
#define MCI_DGV_SETVIDEO_KEY_COLOR          __MSABI_LONG(0x0000400b)
#define MCI_DGV_SETVIDEO_BITSPERPEL         __MSABI_LONG(0x0000400c)

/* flags for the dwFlags parameter of MCI_SIGNAL */

#define MCI_DGV_SIGNAL_AT                   __MSABI_LONG(0x00010000)
#define MCI_DGV_SIGNAL_EVERY                __MSABI_LONG(0x00020000)
#define MCI_DGV_SIGNAL_USERVAL              __MSABI_LONG(0x00040000)
#define MCI_DGV_SIGNAL_CANCEL               __MSABI_LONG(0x00080000)
#define MCI_DGV_SIGNAL_POSITION             __MSABI_LONG(0x00100000)

/* flags for the dwFlags parameter of MCI_STATUS command */

#define MCI_DGV_STATUS_NOMINAL              __MSABI_LONG(0x00020000)
#define MCI_DGV_STATUS_REFERENCE            __MSABI_LONG(0x00040000)
#define MCI_DGV_STATUS_LEFT                 __MSABI_LONG(0x00080000)
#define MCI_DGV_STATUS_RIGHT                __MSABI_LONG(0x00100000)
#define MCI_DGV_STATUS_DISKSPACE            __MSABI_LONG(0x00200000)
#define MCI_DGV_STATUS_INPUT                __MSABI_LONG(0x00400000)
#define MCI_DGV_STATUS_OUTPUT               __MSABI_LONG(0x00800000)
#define MCI_DGV_STATUS_RECORD               __MSABI_LONG(0x01000000)

/* values for dwItem field of MCI_STATUS_PARMS structure */

#define MCI_DGV_STATUS_AUDIO_INPUT          __MSABI_LONG(0x00004000)
#define MCI_DGV_STATUS_HWND                 __MSABI_LONG(0x00004001)
#define MCI_DGV_STATUS_SPEED                __MSABI_LONG(0x00004003)
#define MCI_DGV_STATUS_HPAL                 __MSABI_LONG(0x00004004)
#define MCI_DGV_STATUS_BRIGHTNESS           __MSABI_LONG(0x00004005)
#define MCI_DGV_STATUS_COLOR                __MSABI_LONG(0x00004006)
#define MCI_DGV_STATUS_CONTRAST             __MSABI_LONG(0x00004007)
#define MCI_DGV_STATUS_FILEFORMAT           __MSABI_LONG(0x00004008)
#define MCI_DGV_STATUS_AUDIO_SOURCE         __MSABI_LONG(0x00004009)
#define MCI_DGV_STATUS_GAMMA                __MSABI_LONG(0x0000400a)
#define MCI_DGV_STATUS_MONITOR              __MSABI_LONG(0x0000400b)
#define MCI_DGV_STATUS_MONITOR_METHOD       __MSABI_LONG(0x0000400c)
#define MCI_DGV_STATUS_FRAME_RATE           __MSABI_LONG(0x0000400e)
#define MCI_DGV_STATUS_BASS                 __MSABI_LONG(0x0000400f)
#define MCI_DGV_STATUS_SIZE                 __MSABI_LONG(0x00004010)
#define MCI_DGV_STATUS_SEEK_EXACTLY         __MSABI_LONG(0x00004011)
#define MCI_DGV_STATUS_SHARPNESS            __MSABI_LONG(0x00004012)
#define MCI_DGV_STATUS_SMPTE                __MSABI_LONG(0x00004013)
#define MCI_DGV_STATUS_AUDIO                __MSABI_LONG(0x00004014)
#define MCI_DGV_STATUS_TINT                 __MSABI_LONG(0x00004015)
#define MCI_DGV_STATUS_TREBLE               __MSABI_LONG(0x00004016)
#define MCI_DGV_STATUS_UNSAVED              __MSABI_LONG(0x00004017)
#define MCI_DGV_STATUS_VIDEO                __MSABI_LONG(0x00004018)
#define MCI_DGV_STATUS_VOLUME               __MSABI_LONG(0x00004019)
#define MCI_DGV_STATUS_AUDIO_RECORD         __MSABI_LONG(0x0000401a)
#define MCI_DGV_STATUS_VIDEO_SOURCE         __MSABI_LONG(0x0000401b)
#define MCI_DGV_STATUS_VIDEO_RECORD         __MSABI_LONG(0x0000401c)
#define MCI_DGV_STATUS_STILL_FILEFORMAT     __MSABI_LONG(0x0000401d)
#define MCI_DGV_STATUS_VIDEO_SRC_NUM        __MSABI_LONG(0x0000401e)
#define MCI_DGV_STATUS_FILE_MODE            __MSABI_LONG(0x0000401f)
#define MCI_DGV_STATUS_FILE_COMPLETION      __MSABI_LONG(0x00004020)
#define MCI_DGV_STATUS_WINDOW_VISIBLE       __MSABI_LONG(0x00004021)
#define MCI_DGV_STATUS_WINDOW_MINIMIZED     __MSABI_LONG(0x00004022)
#define MCI_DGV_STATUS_WINDOW_MAXIMIZED     __MSABI_LONG(0x00004023)
#define MCI_DGV_STATUS_KEY_INDEX            __MSABI_LONG(0x00004024)
#define MCI_DGV_STATUS_KEY_COLOR            __MSABI_LONG(0x00004025)
#define MCI_DGV_STATUS_PAUSE_MODE           __MSABI_LONG(0x00004026)
#define MCI_DGV_STATUS_SAMPLESPERSEC        __MSABI_LONG(0x00004027)
#define MCI_DGV_STATUS_AVGBYTESPERSEC       __MSABI_LONG(0x00004028)
#define MCI_DGV_STATUS_BLOCKALIGN           __MSABI_LONG(0x00004029)
#define MCI_DGV_STATUS_BITSPERSAMPLE        __MSABI_LONG(0x0000402a)
#define MCI_DGV_STATUS_BITSPERPEL           __MSABI_LONG(0x0000402b)
#define MCI_DGV_STATUS_FORWARD              __MSABI_LONG(0x0000402c)
#define MCI_DGV_STATUS_AUDIO_STREAM         __MSABI_LONG(0x0000402d)
#define MCI_DGV_STATUS_VIDEO_STREAM         __MSABI_LONG(0x0000402e)

/* flags for dwFlags parameter of MCI_STEP command message */

#define MCI_DGV_STEP_REVERSE                __MSABI_LONG(0x00010000)
#define MCI_DGV_STEP_FRAMES                 __MSABI_LONG(0x00020000)

/* flags for dwFlags parameter of MCI_STOP command message */

#define MCI_DGV_STOP_HOLD                   __MSABI_LONG(0x00010000)

/* flags for dwFlags parameter of MCI_UPDATE command message */

#define MCI_DGV_UPDATE_HDC                  __MSABI_LONG(0x00020000)
#define MCI_DGV_UPDATE_PAINT                __MSABI_LONG(0x00040000)

/* flags for dwFlags parameter of MCI_WHERE command message */

#define MCI_DGV_WHERE_SOURCE                __MSABI_LONG(0x00020000)
#define MCI_DGV_WHERE_DESTINATION           __MSABI_LONG(0x00040000)
#define MCI_DGV_WHERE_FRAME                 __MSABI_LONG(0x00080000)
#define MCI_DGV_WHERE_VIDEO                 __MSABI_LONG(0x00100000)
#define MCI_DGV_WHERE_WINDOW                __MSABI_LONG(0x00200000)
#define MCI_DGV_WHERE_MAX                   __MSABI_LONG(0x00400000)

/* flags for dwFlags parameter of MCI_WINDOW command message */

#define MCI_DGV_WINDOW_HWND                 __MSABI_LONG(0x00010000)
#define MCI_DGV_WINDOW_STATE                __MSABI_LONG(0x00040000)
#define MCI_DGV_WINDOW_TEXT                 __MSABI_LONG(0x00080000)

/* flags for hWnd parameter of MCI_DGV_WINDOW_PARMS parameter block */

#define MCI_DGV_WINDOW_DEFAULT              __MSABI_LONG(0x00000000)

/* parameter block for MCI_WHERE, MCI_PUT, MCI_FREEZE, MCI_UNFREEZE cmds */

typedef struct {
    DWORD_PTR dwCallback;
    RECT    rc;
} MCI_DGV_RECT_PARMS, *LPMCI_DGV_RECT_PARMS;

/* parameter block for MCI_CAPTURE command message */

typedef struct {
    DWORD_PTR dwCallback;
    LPSTR   lpstrFileName;
    RECT    rc;
} MCI_DGV_CAPTURE_PARMSA, *LPMCI_DGV_CAPTURE_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrFileName;
    RECT    rc;
} MCI_DGV_CAPTURE_PARMSW, *LPMCI_DGV_CAPTURE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_CAPTURE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_CAPTURE_PARMS)

/* parameter block for MCI_CLOSE command message */

typedef MCI_GENERIC_PARMS MCI_CLOSE_PARMS, *LPMCI_CLOSE_PARMS;

/* parameter block for MCI_COPY command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwFrom;
    DWORD   dwTo;
    RECT    rc;
    DWORD   dwAudioStream;
    DWORD   dwVideoStream;
} MCI_DGV_COPY_PARMS, *LPMCI_DGV_COPY_PARMS;

/* parameter block for MCI_CUE command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwTo;
} MCI_DGV_CUE_PARMS, *LPMCI_DGV_CUE_PARMS;

/* parameter block for MCI_CUT command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwFrom;
    DWORD   dwTo;
    RECT    rc;
    DWORD   dwAudioStream;
    DWORD   dwVideoStream;
} MCI_DGV_CUT_PARMS, * LPMCI_DGV_CUT_PARMS;

/* parameter block for MCI_DELETE command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwFrom;
    DWORD   dwTo;
    RECT    rc;
    DWORD   dwAudioStream;
    DWORD   dwVideoStream;
} MCI_DGV_DELETE_PARMS, * LPMCI_DGV_DELETE_PARMS;

/* parameter block for MCI_FREEZE command message */

typedef MCI_DGV_RECT_PARMS MCI_DGV_FREEZE_PARMS, * LPMCI_DGV_FREEZE_PARMS;

/* parameter block for MCI_INFO command message */

typedef struct  {
    DWORD_PTR dwCallback;
    LPSTR   lpstrReturn;
    DWORD   dwRetSize;
    DWORD   dwItem;
} MCI_DGV_INFO_PARMSA, * LPMCI_DGV_INFO_PARMSA;

typedef struct  {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrReturn;
    DWORD   dwRetSize;
    DWORD   dwItem;
} MCI_DGV_INFO_PARMSW, *LPMCI_DGV_INFO_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_INFO_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_INFO_PARMS)

/* parameter block for MCI_LIST command message */

typedef struct {
    DWORD_PTR dwCallback;
    LPSTR   lpstrReturn;
    DWORD   dwLength;
    DWORD   dwNumber;
    DWORD   dwItem;
    LPSTR   lpstrAlgorithm;
} MCI_DGV_LIST_PARMSA, *LPMCI_DGV_LIST_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrReturn;
    DWORD   dwLength;
    DWORD   dwNumber;
    DWORD   dwItem;
    LPWSTR  lpstrAlgorithm;
} MCI_DGV_LIST_PARMSW, *LPMCI_DGV_LIST_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_LIST_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_LIST_PARMS)

/* parameter block for MCI_LOAD command message */

typedef MCI_LOAD_PARMSA MCI_DGV_LOAD_PARMSA, * LPMCI_DGV_LOAD_PARMSA;
typedef MCI_LOAD_PARMSW MCI_DGV_LOAD_PARMSW, * LPMCI_DGV_LOAD_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_LOAD_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_LOAD_PARMS)

/* parameter block for MCI_MONITOR command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwSource;
    DWORD   dwMethod;
} MCI_DGV_MONITOR_PARMS, * LPMCI_DGV_MONITOR_PARMS;

/* parameter block for MCI_OPEN command message */

typedef struct {
    DWORD_PTR dwCallback;
    UINT    wDeviceID;
    LPSTR   lpstrDeviceType;
    LPSTR   lpstrElementName;
    LPSTR   lpstrAlias;
    DWORD   dwStyle;
    HWND  hWndParent;
} MCI_DGV_OPEN_PARMSA, *LPMCI_DGV_OPEN_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    UINT    wDeviceID;
    LPWSTR  lpstrDeviceType;
    LPWSTR  lpstrElementName;
    LPWSTR  lpstrAlias;
    DWORD   dwStyle;
    HWND  hWndParent;
} MCI_DGV_OPEN_PARMSW, *LPMCI_DGV_OPEN_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_OPEN_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_OPEN_PARMS)

/* parameter block for MCI_PAUSE command message */

typedef MCI_GENERIC_PARMS MCI_DGV_PAUSE_PARMS, * LPMCI_DGV_PAUSE_PARMS;

/* parameter block for MCI_PASTE command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwTo;
    RECT    rc;
    DWORD   dwAudioStream;
    DWORD   dwVideoStream;
} MCI_DGV_PASTE_PARMS, * LPMCI_DGV_PASTE_PARMS;

/* parameter block for MCI_PLAY command message */

typedef MCI_PLAY_PARMS MCI_DGV_PLAY_PARMS, * LPMCI_DGV_PLAY_PARMS;

/* parameter block for MCI_PUT command message */

typedef MCI_DGV_RECT_PARMS MCI_DGV_PUT_PARMS, * LPMCI_DGV_PUT_PARMS;

/* parameter block for MCI_QUALITY command message */

typedef struct {
    DWORD_PTR   dwCallback;
    DWORD       dwItem;
    LPSTR       lpstrName;
    DWORD       lpstrAlgorithm;
    DWORD       dwHandle;
} MCI_DGV_QUALITY_PARMSA, *LPMCI_DGV_QUALITY_PARMSA;

typedef struct {
    DWORD_PTR   dwCallback;
    DWORD       dwItem;
    LPWSTR      lpstrName;
    DWORD       lpstrAlgorithm;
    DWORD       dwHandle;
} MCI_DGV_QUALITY_PARMSW, *LPMCI_DGV_QUALITY_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_QUALITY_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_QUALITY_PARMS)

/* parameter block for MCI_REALIZE command message */

typedef MCI_GENERIC_PARMS MCI_REALIZE_PARMS, * LPMCI_REALIZE_PARMS;

/* parameter block for MCI_RECORD command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwFrom;
    DWORD   dwTo;
    RECT    rc;
    DWORD   dwAudioStream;
    DWORD   dwVideoStream;
} MCI_DGV_RECORD_PARMS, * LPMCI_DGV_RECORD_PARMS;

/* parameter block for MCI_RESERVE command message */

typedef struct {
    DWORD_PTR dwCallback;
    LPSTR   lpstrPath;
    DWORD   dwSize;
} MCI_DGV_RESERVE_PARMSA, *LPMCI_DGV_RESERVE_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrPath;
    DWORD   dwSize;
} MCI_DGV_RESERVE_PARMSW, *LPMCI_DGV_RESERVE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_RESERVE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_RESERVE_PARMS)

/* parameter block for MCI_RESTORE command message */

typedef struct {
    DWORD_PTR dwCallback;
    LPSTR   lpstrFileName;
    RECT    rc;
} MCI_DGV_RESTORE_PARMSA, *LPMCI_DGV_RESTORE_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrFileName;
    RECT    rc;
} MCI_DGV_RESTORE_PARMSW, *LPMCI_DGV_RESTORE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_RESTORE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_RESTORE_PARMS)

/* parameter block for MCI_RESUME command message */

typedef MCI_GENERIC_PARMS MCI_DGV_RESUME_PARMS, * LPMCI_DGV_RESUME_PARMS;

/* parameter block for MCI_SAVE command message */

typedef struct {
    DWORD_PTR dwCallback;
    LPSTR   lpstrFileName;
    RECT    rc;
} MCI_DGV_SAVE_PARMSA, *LPMCI_DGV_SAVE_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    LPWSTR  lpstrFileName;
    RECT    rc;
} MCI_DGV_SAVE_PARMSW, *LPMCI_DGV_SAVE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_SAVE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_SAVE_PARMS)

/* parameter block for MCI_SET command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwTimeFormat;
    DWORD   dwAudio;
    DWORD   dwFileFormat;
    DWORD   dwSpeed;
} MCI_DGV_SET_PARMS, *LPMCI_DGV_SET_PARMS;

/* parameter block for MCI_SETAUDIO command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwItem;
    DWORD   dwValue;
    DWORD   dwOver;
    LPSTR   lpstrAlgorithm;
    LPSTR   lpstrQuality;
} MCI_DGV_SETAUDIO_PARMSA, *LPMCI_DGV_SETAUDIO_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwItem;
    DWORD   dwValue;
    DWORD   dwOver;
    LPWSTR  lpstrAlgorithm;
    LPWSTR  lpstrQuality;
} MCI_DGV_SETAUDIO_PARMSW, *LPMCI_DGV_SETAUDIO_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_SETAUDIO_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_SETAUDIO_PARMS)

/* parameter block for MCI_SIGNAL command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwPosition;
    DWORD   dwPeriod;
    DWORD   dwUserParm;
} MCI_DGV_SIGNAL_PARMS, * LPMCI_DGV_SIGNAL_PARMS;

/* parameter block for MCI_SETVIDEO command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwItem;
    DWORD   dwValue;
    DWORD   dwOver;
    LPSTR   lpstrAlgorithm;
    LPSTR   lpstrQuality;
    DWORD   dwSourceNumber;
} MCI_DGV_SETVIDEO_PARMSA, *LPMCI_DGV_SETVIDEO_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwItem;
    DWORD   dwValue;
    DWORD   dwOver;
    LPWSTR  lpstrAlgorithm;
    LPWSTR  lpstrQuality;
    DWORD   dwSourceNumber;
} MCI_DGV_SETVIDEO_PARMSW, *LPMCI_DGV_SETVIDEO_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_SETVIDEO_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_SETVIDEO_PARMS)

/* parameter block for MCI_STATUS command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD_PTR dwReturn;
    DWORD   dwItem;
    DWORD   dwTrack;
    LPSTR   lpstrDrive;
    DWORD   dwReference;
} MCI_DGV_STATUS_PARMSA, *LPMCI_DGV_STATUS_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    DWORD_PTR dwReturn;
    DWORD   dwItem;
    DWORD   dwTrack;
    LPWSTR  lpstrDrive;
    DWORD   dwReference;
} MCI_DGV_STATUS_PARMSW, *LPMCI_DGV_STATUS_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_STATUS_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_DGV_STATUS_PARMS)

/* parameter block for MCI_STEP command message */

typedef struct {
    DWORD_PTR dwCallback;
    DWORD   dwFrames;
} MCI_DGV_STEP_PARMS, *LPMCI_DGV_STEP_PARMS;

/* parameter block for MCI_STOP command message */

typedef MCI_GENERIC_PARMS MCI_DGV_STOP_PARMS, * LPMCI_DGV_STOP_PARMS;

/* parameter block for MCI_UNFREEZE command message */

typedef MCI_DGV_RECT_PARMS MCI_DGV_UNFREEZE_PARMS, * LPMCI_DGV_UNFREEZE_PARMS;

/* parameter block for MCI_UPDATE command message */

typedef struct {
    DWORD_PTR dwCallback;
    RECT    rc;
    HDC     hDC;
} MCI_DGV_UPDATE_PARMS, * LPMCI_DGV_UPDATE_PARMS;

/* parameter block for MCI_WHERE command message */

typedef MCI_DGV_RECT_PARMS MCI_DGV_WHERE_PARMS, * LPMCI_DGV_WHERE_PARMS;

/* parameter block for MCI_WINDOW command message */

typedef struct {
    DWORD_PTR dwCallback;
    HWND    hWnd;
    UINT    nCmdShow;
    LPSTR   lpstrText;
} MCI_DGV_WINDOW_PARMSA, *LPMCI_DGV_WINDOW_PARMSA;

typedef struct {
    DWORD_PTR dwCallback;
    HWND    hWnd;
    UINT    nCmdShow;
    LPWSTR  lpstrText;
} MCI_DGV_WINDOW_PARMSW, *LPMCI_DGV_WINDOW_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_DGV_WINDOW_PARMS)

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#endif /* __WINE_DIGITALV_H */
