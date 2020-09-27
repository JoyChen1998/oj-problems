// 计算n为2进制时，有多少个1
int bitcount(int n){
	int cnt = 0;
	while(n) {
		n = n & (n-1);
		cnt ++;
	}
	return cnt;
}

// 让某个数字(state)的第i位表示一个状态。比如 8 => 1000 ,  则如果需要让i位置1，则：
int change_bit(int i, int state) {
	return (state | 1 << i);
} 

// 让某个数字(state)的第i位表示一个状态。比如 8 => 1000 ,  则如果需要判断某位是否为1 则：
bool change_bit(int i, int state) {
	return (state >> i & 1);
} 

//查找一个数组里某个了一个数字（它出现一次）其他数字出现了两次
int find_1_1(int arr[], int n) {
	int ans = 0;
	for(int i =0 ;i < n; i++) 
		ans ^= arr[i];                                   // 两个相同的数进行异或后=0. （异或 =>  相同的二进制位得0， 相异的二进制位得1）
	return ans;
}

//查找一个数组里除了两个数字（出现了一次）其他的数字都出现了两次
int find_1_2(int arr[], int n) {
	int ans = 0, ans1 = 0, ans2 =0;
	for(int i = 0 ;i < n; i++)
		ans ^= arr[i];                                   //  这样会使得ans为两个出现一次的数字的异或结果
	int pos = 0;
	while(((ans >> pos) & 1) != 1) pos ++;               //记录这个异或结果的第一个1（不同位）的位置.
	for(int i = 0; i < n; i++) {
		if (((a[i] >> pos) & 1) != 1) ans1 ^= arr[i];    //分为两组，一组是这一位为0的，一组是这一位为1的。 
		else ans2 ^= arr[i];						     //然后分别进行相异或。即可根据 find_1_1(n)的思路得出两个解
		
	}
	cout<<ans1<<" "<<ans2<<endl;

}