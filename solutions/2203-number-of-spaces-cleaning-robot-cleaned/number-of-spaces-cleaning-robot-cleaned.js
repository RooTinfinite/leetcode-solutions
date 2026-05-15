const numberOfCleanRooms = (room) => {
  const visited = new Set()
  const cleaned = new Set()
  const traverse = (y, x, dy, dx) => {
    if (visited.has(`${[y, x, dy, dx]}`))
      return cleaned.size
    visited.add(`${[y, x, dy, dx]}`)
    cleaned.add(`${[y, x]}`)
    return room[y + dy]?.[x + dx] === 0 
      ? traverse(y + dy, x + dx, dy, dx)
      : traverse(y, x, dx, -dy)
  }
  return traverse(0, 0, 0, 1)
}