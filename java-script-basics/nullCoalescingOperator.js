let a = null;
const mon = a ?? false;
console.log(mon);
// these both lines below and above have the same meaning ,above one is a syntax sugar of the below one.
const mon1 = (a !==null && a !=undefined)?a:false;
console.log(mon1)