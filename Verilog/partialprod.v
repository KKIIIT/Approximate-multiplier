`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:49:30 06/15/2016 
// Design Name: 
// Module Name:    partialprod 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module partialprod(A,B,C);
input[7:0] A,B;
output[15:0] C;
reg [15:0] C;
reg [15:0] stage1,stage2,stage3,stage4,stage5,stage6,stage7,stage8;
reg [15:0] final_stage1,final_stage2,final_stage3,final_stage4,final_stage5,final_stage6,final_stage7,final_stage8;
//for stage1
always @(*) 
begin
if(B[7]==1'b1)begin
stage1[15]<=1'b0;
stage1[14:7]<=A[7:0];
stage1[6:0]<=1'b0;
end
else if(B[7]==1'b0)begin
stage1[15:0]<=1'b0;
end
if(B[6]==1'b1)begin
stage2[15:14]<=1'b0;
stage2[13:6]<=A[7:0];
stage2[5:0]<=1'b0;
end
else if(B[6]==1'b0)begin
stage2[15:0]<=1'b0;
end
if(B[5]==1'b1)begin
stage3[15:13]<=1'b0;
stage3[12:5]<=A[7:0];
stage3[4:0]<=1'b0;
end
else if(B[5]==1'b0)begin
stage3[15:0]<=1'b0;
end
if(B[4]==1'b1)begin
stage4[15:12]<=1'b0;
stage4[11:4]<=A[7:0];
stage4[3:0]<=1'b0;
end
else if(B[4]==1'b0)begin
stage4[15:0]<=1'b0;
end
if(B[3]==1'b1)begin
stage5[15:11]<=1'b0;
stage5[10:3]<=A[7:0];
stage5[2:0]<=1'b0;
end
else if(B[3]==1'b0)begin
stage5[15:0]<=1'b0;
end
if(B[2]==1'b1)begin
stage6[15:10]<=1'b0;
stage6[9:2]<=A[7:0];
stage6[1:0]<=1'b0;
end
else if(B[2]==1'b0)begin
stage6[15:0]<=1'b0;
end
if(B[1]==1'b1)begin
stage7[15:9]<=1'b0;
stage7[8:1]<=A[7:0];
stage7[0]<=1'b0;
end
else if(B[1]==1'b0)begin
stage7[15:0]<=1'b0;
end
if(B[0]==1'b1)begin
stage8[15:8]<=1'b0;
stage8[7:0]<=A[7:0];
end
else if(B[0]==1'b0)begin
stage8[15:0]<=1'b0;
end
final_stage1[15:0]<=stage1[15:0];//1
final_stage2[15:0]<=final_stage1[15:0]+stage2[15:0];//2
final_stage3[15:0]<=final_stage2[15:0]+stage3[15:0];//3
final_stage4[15:0]<=final_stage3[15:0]+stage4[15:0];//4
final_stage5[15:0]<=final_stage4[15:0]+stage5[15:0];//5
final_stage6[15:0]<=final_stage5[15:0]+stage6[15:0];//6
final_stage7[15:0]<=final_stage6[15:0]+stage7[15:0];//7
final_stage8[15:0]<=final_stage7[15:0]+stage8[15:0];//8
//bluespecverilog
//systemcverilog
C[15:0]<=final_stage8[15:0];//correct answer
end
endmodule
