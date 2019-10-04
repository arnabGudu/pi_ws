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

class tuning {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.lkp = null;
      this.lkd = null;
      this.lki = null;
      this.akp = null;
      this.akd = null;
      this.aki = null;
      this.vel = null;
    }
    else {
      if (initObj.hasOwnProperty('lkp')) {
        this.lkp = initObj.lkp
      }
      else {
        this.lkp = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('lkd')) {
        this.lkd = initObj.lkd
      }
      else {
        this.lkd = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('lki')) {
        this.lki = initObj.lki
      }
      else {
        this.lki = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('akp')) {
        this.akp = initObj.akp
      }
      else {
        this.akp = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('akd')) {
        this.akd = initObj.akd
      }
      else {
        this.akd = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('aki')) {
        this.aki = initObj.aki
      }
      else {
        this.aki = new std_msgs.msg.Int16();
      }
      if (initObj.hasOwnProperty('vel')) {
        this.vel = initObj.vel
      }
      else {
        this.vel = new std_msgs.msg.Int16();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type tuning
    // Serialize message field [lkp]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.lkp, buffer, bufferOffset);
    // Serialize message field [lkd]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.lkd, buffer, bufferOffset);
    // Serialize message field [lki]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.lki, buffer, bufferOffset);
    // Serialize message field [akp]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.akp, buffer, bufferOffset);
    // Serialize message field [akd]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.akd, buffer, bufferOffset);
    // Serialize message field [aki]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.aki, buffer, bufferOffset);
    // Serialize message field [vel]
    bufferOffset = std_msgs.msg.Int16.serialize(obj.vel, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type tuning
    let len;
    let data = new tuning(null);
    // Deserialize message field [lkp]
    data.lkp = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [lkd]
    data.lkd = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [lki]
    data.lki = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [akp]
    data.akp = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [akd]
    data.akd = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [aki]
    data.aki = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    // Deserialize message field [vel]
    data.vel = std_msgs.msg.Int16.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 14;
  }

  static datatype() {
    // Returns string type for a message object
    return 'gazebo_ipbot/tuning';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8cd8aa6abc2468ca69bf190c916f0446';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Int16 lkp
    std_msgs/Int16 lkd
    std_msgs/Int16 lki
    std_msgs/Int16 akp
    std_msgs/Int16 akd
    std_msgs/Int16 aki
    std_msgs/Int16 vel
    
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
    const resolved = new tuning(null);
    if (msg.lkp !== undefined) {
      resolved.lkp = std_msgs.msg.Int16.Resolve(msg.lkp)
    }
    else {
      resolved.lkp = new std_msgs.msg.Int16()
    }

    if (msg.lkd !== undefined) {
      resolved.lkd = std_msgs.msg.Int16.Resolve(msg.lkd)
    }
    else {
      resolved.lkd = new std_msgs.msg.Int16()
    }

    if (msg.lki !== undefined) {
      resolved.lki = std_msgs.msg.Int16.Resolve(msg.lki)
    }
    else {
      resolved.lki = new std_msgs.msg.Int16()
    }

    if (msg.akp !== undefined) {
      resolved.akp = std_msgs.msg.Int16.Resolve(msg.akp)
    }
    else {
      resolved.akp = new std_msgs.msg.Int16()
    }

    if (msg.akd !== undefined) {
      resolved.akd = std_msgs.msg.Int16.Resolve(msg.akd)
    }
    else {
      resolved.akd = new std_msgs.msg.Int16()
    }

    if (msg.aki !== undefined) {
      resolved.aki = std_msgs.msg.Int16.Resolve(msg.aki)
    }
    else {
      resolved.aki = new std_msgs.msg.Int16()
    }

    if (msg.vel !== undefined) {
      resolved.vel = std_msgs.msg.Int16.Resolve(msg.vel)
    }
    else {
      resolved.vel = new std_msgs.msg.Int16()
    }

    return resolved;
    }
};

module.exports = tuning;
