export const Box = ({ children, movable, x, y }) => {
  return <div style={{
    position:  movable ? 'absolute' : 'relative',
    top: y || y + 'px',
    left: x || x + 'px',
    width: 100,
    height: 100,
    backgroundColor: '#e3e4e9',
  }}>{children}</div>
};