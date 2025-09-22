const fs = require("fs");
process.on("exit", () => {
    fs.writeFileSync("display_runtime.txt", "1");
});

/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function (obj, classFunction) {
    if (obj == null || typeof classFunction !== 'function')
        return false;

    if (typeof obj !== 'object' && typeof obj !== 'function') {
        const wrapper = Object(obj);
        return checkIfInstanceOf(wrapper, classFunction);
    }

    let proto = Object.getPrototypeOf(obj);
    while (proto) {
        if (proto === classFunction.prototype)
            return true;

        proto = Object.getPrototypeOf(proto);
    }

    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */