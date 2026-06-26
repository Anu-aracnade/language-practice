let website = {
    name:'Anubhab',
    age: 20,
    human:true
};
// here 'website' is the object and name, age, human are property.

console.log(website);

console.log(website.age);

website.name="Daisy";
console.log(website.name);
console.log(website['name']);

let property ='age';
console.log(website[property]);