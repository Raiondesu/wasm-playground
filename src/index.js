import init from './cpp/index.js';

const module = await init();
console.log("Module has been instantiated!", module);