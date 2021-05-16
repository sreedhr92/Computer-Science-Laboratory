
var events = require('events');

var eventEmitter = new events.EventEmitter();
var helper = function helper() {
    console.log('\nPlease help me\n');
}

eventEmitter.addListener('help',helper);
eventEmitter.emit('help');