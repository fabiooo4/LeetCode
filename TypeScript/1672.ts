let accounts: number[][] = [[1,2,3],[3,2,1]];

function maximumWealth(accounts: number[][]): number {
    let wealth: number[] = [];
    accounts.forEach(customer => {
        let sum: number = 0;
        customer.forEach(bank => {
            sum = sum + bank;
        })
        wealth.push(sum);
    })
    console.log(wealth[wealth.indexOf(Math.max(...wealth))]);
    return wealth[wealth.indexOf(Math.max(...wealth))];
};

maximumWealth(accounts);
