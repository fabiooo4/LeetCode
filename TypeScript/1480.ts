let nums: number[] = [1, 2, 3, 4];

function runningSum(nums: number[]): number[] {
    let result: number[] = [];
    for (let i = 0; i < nums.length; i++) {
        let sum: number = 0;
        for (let j = 0; j <= i; j++) {
            sum = sum + nums[j];
        }
        result.push(sum);
    }
    console.log(result);
    return result;
};

runningSum(nums);
