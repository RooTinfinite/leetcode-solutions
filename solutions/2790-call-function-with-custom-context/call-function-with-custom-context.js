Function.prototype.callPolyfill = function (context, ...args) {
  return this.apply(context, args);
};