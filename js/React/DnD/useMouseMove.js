import { useEffect, useState } from "react";

export const useMouseMove = () => {
  const [coords, setCoords] = useState({ x: 0, y: 0});

  const onMouseMove = (event) => setCoords({x: event.pageX, y: event.pageY });

  useEffect(() => {
    window.addEventListener('mousemove', onMouseMove);

    return () => window.removeEventListener('mousemove', onMouseMove);
  }, []);

  return coords;
};