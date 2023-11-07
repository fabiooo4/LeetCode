let num: number = 11891;

function minMaxDifference(num: number): number {
    let nums: string[] = num.toString().split('');
    let notZero: string;
    let notNine: string;


    for (let digit of nums) {
        if (digit != '0') {
            notZero = digit;
            break;
        }
    }

    for (let digit of nums) {
        if (digit != '9') {
            notNine = digit;
            break;
        }
    }

    let max = Number.parseInt(nums.map(digit => {
        if (digit == notNine) {
            return '9'
        } else {
            return digit;
        }
    }).join(''));

    let min = Number.parseInt(nums.map(digit => {
        if (digit == notZero) {
            return '0'
        } else {
            return digit;
        }
    }).join(''));

    return max - min;
};

console.log(minMaxDifference(num));
minMaxDifference(num);
