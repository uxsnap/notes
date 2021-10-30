import { useState } from "react";

const tabsStyles = {
  display: "flex",
  alignItems: "center"
};

const tabStyles = {
  fontSize: 18,
  fontWeight: 500,
  color: "#e3e4e9",
  width: 200,
  position: "relative",
  textAlign: "center",
  borderBottom: "4px solid #e3e4e0",
  paddingBottom: 10
};

const currentStyles = (active) => ({
  background: "#b3cde0",
  height: 5,
  borderRadius: 10,
  transition: ".2s",
  position: "absolute",
  transform: `translate(${active * 100}%)`,
  left: 0,
  bottom: -5,
  width: "100%",
  zIndex: 100
});

export const Tabs = ({ tabs }) => {
  const [active, setActive] = useState(0);

  return (
    <div style={tabsStyles}>
      {tabs.map((tab, index) => (
        <div
          key={tab.value}
          style={tabStyles}
          onClick={() => {
            setActive(index);
          }}
        >
          {tab.label}
          {!index && <div style={currentStyles(active)}></div>}
        </div>
      ))}
    </div>
  );
};
