
"use strict";

let TerrainReport = require('./TerrainReport.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let LandingTarget = require('./LandingTarget.js');
let ESCInfoItem = require('./ESCInfoItem.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let State = require('./State.js');
let PlayTuneV2 = require('./PlayTuneV2.js');
let StatusText = require('./StatusText.js');
let PositionTarget = require('./PositionTarget.js');
let CameraImageCaptured = require('./CameraImageCaptured.js');
let VFR_HUD = require('./VFR_HUD.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let ESCInfo = require('./ESCInfo.js');
let GPSRAW = require('./GPSRAW.js');
let Trajectory = require('./Trajectory.js');
let NavControllerOutput = require('./NavControllerOutput.js');
let LogEntry = require('./LogEntry.js');
let GPSINPUT = require('./GPSINPUT.js');
let GPSRTK = require('./GPSRTK.js');
let HilGPS = require('./HilGPS.js');
let VehicleInfo = require('./VehicleInfo.js');
let CommandCode = require('./CommandCode.js');
let BatteryStatus = require('./BatteryStatus.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let Altitude = require('./Altitude.js');
let ESCStatusItem = require('./ESCStatusItem.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let EstimatorStatus = require('./EstimatorStatus.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let ESCStatus = require('./ESCStatus.js');
let ParamValue = require('./ParamValue.js');
let Mavlink = require('./Mavlink.js');
let LogData = require('./LogData.js');
let HilControls = require('./HilControls.js');
let MountControl = require('./MountControl.js');
let WaypointReached = require('./WaypointReached.js');
let ManualControl = require('./ManualControl.js');
let RTCM = require('./RTCM.js');
let Param = require('./Param.js');
let Vibration = require('./Vibration.js');
let RTKBaseline = require('./RTKBaseline.js');
let HomePosition = require('./HomePosition.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let Waypoint = require('./Waypoint.js');
let ESCTelemetry = require('./ESCTelemetry.js');
let RCOut = require('./RCOut.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let CellularStatus = require('./CellularStatus.js');
let ActuatorControl = require('./ActuatorControl.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let DebugValue = require('./DebugValue.js');
let HilSensor = require('./HilSensor.js');
let WaypointList = require('./WaypointList.js');
let RadioStatus = require('./RadioStatus.js');
let FileEntry = require('./FileEntry.js');
let MagnetometerReporter = require('./MagnetometerReporter.js');
let ExtendedState = require('./ExtendedState.js');
let ESCTelemetryItem = require('./ESCTelemetryItem.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let Thrust = require('./Thrust.js');
let Tunnel = require('./Tunnel.js');
let RCIn = require('./RCIn.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');

module.exports = {
  TerrainReport: TerrainReport,
  TimesyncStatus: TimesyncStatus,
  LandingTarget: LandingTarget,
  ESCInfoItem: ESCInfoItem,
  OnboardComputerStatus: OnboardComputerStatus,
  State: State,
  PlayTuneV2: PlayTuneV2,
  StatusText: StatusText,
  PositionTarget: PositionTarget,
  CameraImageCaptured: CameraImageCaptured,
  VFR_HUD: VFR_HUD,
  AttitudeTarget: AttitudeTarget,
  ESCInfo: ESCInfo,
  GPSRAW: GPSRAW,
  Trajectory: Trajectory,
  NavControllerOutput: NavControllerOutput,
  LogEntry: LogEntry,
  GPSINPUT: GPSINPUT,
  GPSRTK: GPSRTK,
  HilGPS: HilGPS,
  VehicleInfo: VehicleInfo,
  CommandCode: CommandCode,
  BatteryStatus: BatteryStatus,
  CamIMUStamp: CamIMUStamp,
  Altitude: Altitude,
  ESCStatusItem: ESCStatusItem,
  WheelOdomStamped: WheelOdomStamped,
  EstimatorStatus: EstimatorStatus,
  ADSBVehicle: ADSBVehicle,
  ESCStatus: ESCStatus,
  ParamValue: ParamValue,
  Mavlink: Mavlink,
  LogData: LogData,
  HilControls: HilControls,
  MountControl: MountControl,
  WaypointReached: WaypointReached,
  ManualControl: ManualControl,
  RTCM: RTCM,
  Param: Param,
  Vibration: Vibration,
  RTKBaseline: RTKBaseline,
  HomePosition: HomePosition,
  OpticalFlowRad: OpticalFlowRad,
  Waypoint: Waypoint,
  ESCTelemetry: ESCTelemetry,
  RCOut: RCOut,
  CompanionProcessStatus: CompanionProcessStatus,
  CellularStatus: CellularStatus,
  ActuatorControl: ActuatorControl,
  OverrideRCIn: OverrideRCIn,
  DebugValue: DebugValue,
  HilSensor: HilSensor,
  WaypointList: WaypointList,
  RadioStatus: RadioStatus,
  FileEntry: FileEntry,
  MagnetometerReporter: MagnetometerReporter,
  ExtendedState: ExtendedState,
  ESCTelemetryItem: ESCTelemetryItem,
  GlobalPositionTarget: GlobalPositionTarget,
  Thrust: Thrust,
  Tunnel: Tunnel,
  RCIn: RCIn,
  HilActuatorControls: HilActuatorControls,
  HilStateQuaternion: HilStateQuaternion,
};
