import QtQuick 2.15

Timer {
    property var triggeredCallback

    function delay(delayTime, cb) {
        this.stop();
        this.interval = delayTime;
        this.repeat = false;
        this.triggeredCallback = cb
        this.start();
    }

    onTriggered: function() {
        triggeredCallback()
    }
}
