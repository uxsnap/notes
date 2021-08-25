import { useMouseMove } from './useMouseMove';
import { Box } from './Box';
import { useCallback, useEffect, useState } from 'react';

/* 
  Simple DnD functionality without using onDrag* like events
  Sorting will be added sooner or later
*/

const containerStyles = {
  padding: 10,
  background: '#2b4aac',
  width: 150,
};

const copyFromAnother = (first, second, ind) => {
  const nFirst = [...first, second[ind]];
  const nSecond = [...second];
  nSecond.splice(ind, 1);
  return [nFirst, nSecond];
};

function App() {
  const { x, y } = useMouseMove();
  const [movable, setMovable] = useState(-1);
  const [items, setItems] = useState([1, 2, 3, 4, 5]);
  const [selectedItems, setSelectedItems] = useState([]);
  const [curContainer, setCurContainer] = useState('container');
  
  const onMouseUp = useCallback(() => {
    let arr = curContainer === 'container' ? selectedItems : items;
    const item = arr.findIndex(i => i === movable);
    setMovable(-1);
    if (item === -1) return;
    const order = curContainer === 'container' ? [items, selectedItems] : [selectedItems, items];
    const res = copyFromAnother(...order, item);
    if (curContainer === 'selected') {
      let tmp = res[0];
      res[0] = res[1];
      res[1] = tmp;
    }
    setItems(res[0]);
    setSelectedItems(res[1]);
  }, [curContainer, items, selectedItems]);

  useEffect(() => {
    window.addEventListener('mouseup', onMouseUp);
    return () => window.removeEventListener('mouseup', onMouseUp);
  }, [onMouseUp]);

  return (
    <div style={{ display: 'flex' }} className="App">
      <div 
        style={containerStyles} 
        onMouseEnter={() => setCurContainer('container')}
      >
        {items.map((item) => (
          <div 
            key={`container_${item}`}
            style={{ marginTop: 10, display: movable === item ? 'none' : 'block' }} 
            onMouseDown={() => setMovable(item)} 
          >
            <Box>{item}</Box>
          </div>
        ))}
      </div>

      <div
        style={{ ...containerStyles, marginLeft: 40 }} 
        onMouseEnter={() => setCurContainer('selected')}
      >
        {selectedItems.map((item) => (
          <div
            key={`selected_${item}`}
            style={{ marginTop: 10, display: movable === item ? 'none' : 'block' }}
            onMouseDown={() => setMovable(item)}
          >
            <Box>{item}</Box>
          </div>
        ))}
      </div>

      {movable !== -1 && (
          <div style={{ pointerEvents: 'none' }}>
            <Box movable={movable} x={x} y={y} />
          </div>
        )
      }
    </div>
  );
}

export default App;
