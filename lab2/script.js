console.clear();
const inquirer = require('inquirer');

const questions = [
  {
    type: 'input',
    name: 'diameterCilinder',
    message: "Enter diameter of cilinder:\t",
  },
	{
    type: 'input',
    name: 'heightCilinder',
    message: "Enter height of cilinder:\t",
  },
	{
    type: 'input',
    name: 'lengthStep',
    message: "Enter step lenght:\t",
  },
];

const diameterCilinder = 4; // santimeters
const heightCilinder = 10; // santimeters
const lengthStep = 5; // santimeters

inquirer.prompt(questions).then(() => {
  console.log(`Fine`);
});

const result = heightCilinder * Math.sqrt(Math.pow(lengthStep, 2) + Math.pow(Math.PI * diameterCilinder, 2));

console.warn('=========================================\nResult:\t\t' + result + '\nBut count is\t' + Math.floor(result) + '\n=========================================');
