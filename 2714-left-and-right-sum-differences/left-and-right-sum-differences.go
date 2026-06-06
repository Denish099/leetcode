func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func leftRightDifference(nums []int) []int {
    var n int = len(nums)
    var lSum []int = make([]int,n,n)

    sum:= 0

    for i:=0;i<n;i++ {
        lSum[i] = sum;
        sum +=nums[i]
    }

    var rSum []int = make([]int,n,n)
    sum = 0
    for i:=n-1;i>=0;i-- {
        rSum[i] = sum
        sum+=nums[i]
    }

    var ans []int = make([]int,n,n)
    for i:= 0;i<n;i++{
        ans[i] = abs(lSum[i] - rSum[i])
    }

    return ans;

    
}