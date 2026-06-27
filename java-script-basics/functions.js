function intro(name) {
    console.log ('Hi! '+ name);
}
intro('Anubhab');

function multiply(num1, num2){
    const product = num1 * num2;
}
multiply(2,3); // undefined as no return type mentioned.

function sum(num1, num2){
    return num1 + num2;
}
console.log(sum (2,4));

// fuctions are created for two reasons one is for :
// 1.to perform an action.
// 2.to calculate some value and return some the output.