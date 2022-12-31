// Auto-generated. Do not edit!

// (in-package beginner.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class test {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.years = null;
      this.age = null;
    }
    else {
      if (initObj.hasOwnProperty('years')) {
        this.years = initObj.years
      }
      else {
        this.years = 0.0;
      }
      if (initObj.hasOwnProperty('age')) {
        this.age = initObj.age
      }
      else {
        this.age = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type test
    // Serialize message field [years]
    bufferOffset = _serializer.float32(obj.years, buffer, bufferOffset);
    // Serialize message field [age]
    bufferOffset = _serializer.uint8(obj.age, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type test
    let len;
    let data = new test(null);
    // Deserialize message field [years]
    data.years = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [age]
    data.age = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'beginner/test';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6616f4f93356a20eba531c90e0875eb4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 years
    uint8 age
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new test(null);
    if (msg.years !== undefined) {
      resolved.years = msg.years;
    }
    else {
      resolved.years = 0.0
    }

    if (msg.age !== undefined) {
      resolved.age = msg.age;
    }
    else {
      resolved.age = 0
    }

    return resolved;
    }
};

module.exports = test;
