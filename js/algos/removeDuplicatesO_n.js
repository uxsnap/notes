/* Won't work with objects and other structured data */

export const removeDuplicatesO_n = (arr) => {
	const hashMap = {};
	const newArr = [];

	for (let i = 0; i < arr.length; i++) {
		if (!hashMap[arr[i]]) {
			hashMap[arr[i]] = 1;
			newArr.push(arr[i]);
		} 
	}

	return newArr;
}
