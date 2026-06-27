function arrInputDisplayEven(array) {
    for (const elm of array) {
        if (elm % 2 === 0)
            console.log(elm);
    }
}
arrInputDisplayEven([1, 2, 3, 4, 5, 6]);

function arrInputDisplayOdd(array) {
    for (const el of array) {
        if (el % 2 === 0) continue;
        console.log(el);
    }

}
arrInputDisplayOdd([1, 2, 3, 4, 5, 6]);