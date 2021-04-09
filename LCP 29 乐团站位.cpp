/*
某乐团的演出场地可视作 num * num 的二维矩阵 grid（左上角坐标为 [0,0])，每个位置站有一位成员。乐团共有 9 种乐器，乐器编号为 1~9，每位成员持有 1 个乐器。

为保证声乐混合效果，成员站位规则为：自 grid 左上角开始顺时针螺旋形向内循环以 1，2，...，9 循环重复排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/SNJvJP
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        unsigned long long ans, total = 0, level, temp = num - 1;
        level = min(min(num-1-xPos, xPos), min(num-1-yPos, yPos));
        for (int i = 0; i < level; i ++){
            total += 4*temp;
            temp -= 2;
        }
        xPos -= level;
        yPos -= level;
        num -= level * 2;
        if (xPos == 0){
            total += (unsigned long long)yPos + 1;
        } else if (yPos == num - 1){
            total += (unsigned long long)num + (unsigned long long)xPos;
        } else if (xPos == num - 1){
            total += (unsigned long long)num * 3 - (unsigned long long)yPos - 2;
        } else if (yPos == 0){
            total += (unsigned long long)num * 4 - (unsigned long long)xPos - 3;
        }
        ans = total % 9 == 0 ? 9 : total % 9;
        return ans;
    }
};