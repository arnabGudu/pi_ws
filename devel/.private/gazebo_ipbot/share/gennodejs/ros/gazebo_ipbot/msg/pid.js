// Auto-generated. Do not edit!

// (in-package gazebo_ipbot.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class pid {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.linear = null;
      this.angular = null;
    }
    else {
      if (initObj.hasOwnProperty('linear')) {
        this.linear = initObj.linear
      }
      else {
        this.linear = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('angular')) {
        this.angular = initObj.angular
      }
      else {
        this.angular = new std_msgs.msg.Int16();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type pid
    // Serialize message field [linear]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.linear, buffer, bufferOffset);
    // Serialize message field [angular]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.angular, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pid
    let len;
    let data = new pid(null);
    // Deserialize message field [linear]
    data.linear = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [angular]
    data.angular = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'gazebo_ipbot/pid';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'daee48bdd9b022a2534221391301bf32';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Int16 linear
    std_msgs/Int16 angular
    
    ================================================================================
    MSG: std_msgs/Int16
    int16 data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pid(null);
    if (msg.linear !== undefined) {
      resolved.linear = std_msgs.msg.Int16.Resolve(msg.linear)
    }
    else {
      resolved.linear = new std_msgs.msg.Int16()
    }

    if (msg.angular !== undefined) {
      resolved.angular = std_msgs.msg.Int16.Resolve(msg.angular)
    }
    else {
      resolved.angular = new std_msgs.msg.Int16()
    }

    return resolved;
    }
};

module.exports = pid;
