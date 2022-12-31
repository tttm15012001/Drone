
"use strict";

let CommandAck = require('./CommandAck.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let WaypointClear = require('./WaypointClear.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let FileWrite = require('./FileWrite.js')
let MountConfigure = require('./MountConfigure.js')
let CommandBool = require('./CommandBool.js')
let FileRename = require('./FileRename.js')
let FileMakeDir = require('./FileMakeDir.js')
let SetMode = require('./SetMode.js')
let FileOpen = require('./FileOpen.js')
let MessageInterval = require('./MessageInterval.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let ParamGet = require('./ParamGet.js')
let StreamRate = require('./StreamRate.js')
let ParamSet = require('./ParamSet.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let CommandInt = require('./CommandInt.js')
let SetMavFrame = require('./SetMavFrame.js')
let CommandHome = require('./CommandHome.js')
let FileRemove = require('./FileRemove.js')
let FileChecksum = require('./FileChecksum.js')
let CommandTOL = require('./CommandTOL.js')
let LogRequestData = require('./LogRequestData.js')
let WaypointPull = require('./WaypointPull.js')
let FileList = require('./FileList.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let FileTruncate = require('./FileTruncate.js')
let FileRead = require('./FileRead.js')
let ParamPush = require('./ParamPush.js')
let FileClose = require('./FileClose.js')
let ParamPull = require('./ParamPull.js')
let WaypointPush = require('./WaypointPush.js')
let CommandLong = require('./CommandLong.js')
let LogRequestList = require('./LogRequestList.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')

module.exports = {
  CommandAck: CommandAck,
  CommandTriggerInterval: CommandTriggerInterval,
  WaypointClear: WaypointClear,
  CommandVtolTransition: CommandVtolTransition,
  FileWrite: FileWrite,
  MountConfigure: MountConfigure,
  CommandBool: CommandBool,
  FileRename: FileRename,
  FileMakeDir: FileMakeDir,
  SetMode: SetMode,
  FileOpen: FileOpen,
  MessageInterval: MessageInterval,
  LogRequestEnd: LogRequestEnd,
  ParamGet: ParamGet,
  StreamRate: StreamRate,
  ParamSet: ParamSet,
  WaypointSetCurrent: WaypointSetCurrent,
  CommandInt: CommandInt,
  SetMavFrame: SetMavFrame,
  CommandHome: CommandHome,
  FileRemove: FileRemove,
  FileChecksum: FileChecksum,
  CommandTOL: CommandTOL,
  LogRequestData: LogRequestData,
  WaypointPull: WaypointPull,
  FileList: FileList,
  VehicleInfoGet: VehicleInfoGet,
  FileTruncate: FileTruncate,
  FileRead: FileRead,
  ParamPush: ParamPush,
  FileClose: FileClose,
  ParamPull: ParamPull,
  WaypointPush: WaypointPush,
  CommandLong: CommandLong,
  LogRequestList: LogRequestList,
  FileRemoveDir: FileRemoveDir,
  CommandTriggerControl: CommandTriggerControl,
};
