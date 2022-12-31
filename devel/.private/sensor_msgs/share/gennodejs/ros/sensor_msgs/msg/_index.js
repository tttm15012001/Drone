
"use strict";

let MagneticField = require('./MagneticField.js');
let BatteryState = require('./BatteryState.js');
let Joy = require('./Joy.js');
let RegionOfInterest = require('./RegionOfInterest.js');
let JoyFeedbackArray = require('./JoyFeedbackArray.js');
let NavSatFix = require('./NavSatFix.js');
let CompressedImage = require('./CompressedImage.js');
let TimeReference = require('./TimeReference.js');
let NavSatStatus = require('./NavSatStatus.js');
let LaserEcho = require('./LaserEcho.js');
let PointCloud = require('./PointCloud.js');
let Temperature = require('./Temperature.js');
let Illuminance = require('./Illuminance.js');
let MultiEchoLaserScan = require('./MultiEchoLaserScan.js');
let LaserScan = require('./LaserScan.js');
let CameraInfo = require('./CameraInfo.js');
let Image = require('./Image.js');
let PointField = require('./PointField.js');
let Imu = require('./Imu.js');
let JointState = require('./JointState.js');
let JoyFeedback = require('./JoyFeedback.js');
let ChannelFloat32 = require('./ChannelFloat32.js');
let FluidPressure = require('./FluidPressure.js');
let RelativeHumidity = require('./RelativeHumidity.js');
let MultiDOFJointState = require('./MultiDOFJointState.js');
let Range = require('./Range.js');
let PointCloud2 = require('./PointCloud2.js');

module.exports = {
  MagneticField: MagneticField,
  BatteryState: BatteryState,
  Joy: Joy,
  RegionOfInterest: RegionOfInterest,
  JoyFeedbackArray: JoyFeedbackArray,
  NavSatFix: NavSatFix,
  CompressedImage: CompressedImage,
  TimeReference: TimeReference,
  NavSatStatus: NavSatStatus,
  LaserEcho: LaserEcho,
  PointCloud: PointCloud,
  Temperature: Temperature,
  Illuminance: Illuminance,
  MultiEchoLaserScan: MultiEchoLaserScan,
  LaserScan: LaserScan,
  CameraInfo: CameraInfo,
  Image: Image,
  PointField: PointField,
  Imu: Imu,
  JointState: JointState,
  JoyFeedback: JoyFeedback,
  ChannelFloat32: ChannelFloat32,
  FluidPressure: FluidPressure,
  RelativeHumidity: RelativeHumidity,
  MultiDOFJointState: MultiDOFJointState,
  Range: Range,
  PointCloud2: PointCloud2,
};
