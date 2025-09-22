var checkIfInstanceOf = function(obj, classFunction) {
  if (typeof classFunction !== "function") return false;

  if (obj === null || obj === undefined) return false;

  let proto = Object.getPrototypeOf(obj);
  while (proto !== null) {
    if (proto.constructor === classFunction) return true;
    proto = Object.getPrototypeOf(proto);
  }

  return false;
};
