const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const ticToeArr = [
	[0, 0, 0], 
	[0, 0, 0], 
	[0, 0, 0]
];
let isPlayer = true;

const editTicToeArr = (col, row, isPlayer = false) => {
	if (ticToeArr[row][col]) {
		if (isPlayer) {
			console.log('Field is not empty, choose another!');
			return promptOnUsersTurn();
		} 
		return robotTurn();
	}
	ticToeArr[row][col] = isPlayer ? 'x' : 'o';
	if (isPlayer) return;
	console.log(`\n${ticToeArr[0][0]} | ${ticToeArr[0][1]} | ${ticToeArr[0][2]}`);
	console.log('________')
	console.log(`${ticToeArr[1][0]} | ${ticToeArr[1][1]} | ${ticToeArr[1][2]}`);
	console.log('________');
	console.log(`${ticToeArr[2][0]} | ${ticToeArr[2][1]} | ${ticToeArr[2][2]}\n`);
};


const checkIfGameHasEnded = (isPlayer = false) => {
	const sum = isPlayer ? 'xxx' : 'ooo';
	for (let i = 0; i < 3; i++) {
		if (ticToeArr[i].reduce((a, b) => a + b, '') === sum) return true;
		let verticalSum = '';
		for (let j = 0; j < 3; j++) {
			verticalSum += ticToeArr[j][i];
		}
		if (verticalSum === sum) return true;
	}

	let diagonalSum = '';
	let altDiagonalSum = '';
	for (let k = 0; k < 3; k++) {
		diagonalSum += ticToeArr[k][k];
		altDiagonalSum += ticToeArr[2 - k][k];
	}
	if (diagonalSum === sum) return true;
	if (altDiagonalSum === sum) return true;

	return false;
};

const promptOnUsersTurn = (isPlayer = true) => {
	rl.question('Prompt col and row numbers (Example: "1 2"): ', (ans) => {
		const nums = ans.trim().split(' ').map((num) => parseInt(num)).filter((num) => num < 3);
		if (nums.length !== 2) {
			console.log('Wrong input!');
			return promptOnUsersTurn();
		}
		editTicToeArr(...nums, true);
		if (checkIfGameHasEnded(true)) {
			console.log('\nYou won!');
			return rl.close();
		}
		return robotTurn();
	});
};

const robotTurn = () => {
	const col = Math.floor(Math.random() * 3);
	const row = Math.floor(Math.random() * 3);
	editTicToeArr(col, row);
	if (checkIfGameHasEnded()) {
		console.log('\nRobot won!');
		return rl.close();
	}
	return promptOnUsersTurn();
};

rl.question('Wanna play? y/n ', (answer) => {
	if (answer !== 'y') {
		rl.close();
		return;
	}
	promptOnUsersTurn();
});

rl.on("close", () => console.log("---- End ----"));