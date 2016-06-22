`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    01:40:38 06/21/2016 
// Design Name: 
// Module Name:    LOD 
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
module LOD(A,L,C);
input [7:0] A,L;
output [15:0] C;
reg [5:0] B;
reg [15:0] C;
reg lead=0,count=0;
integer i,j;
reg [15:0] stage1,stage2,stage3,stage4,stage5,stage6,stage7,stage8;
reg [15:0] final_stage1,final_stage2,final_stage3,final_stage4,final_stage5,final_stage6,final_stage7,final_stage8;
always@(*)begin
for (i = 0; i < 8; i = i +1) begin
if(L[i]==1'b1)begin
if(lead==0)begin
lead <= i;
end
else begin
count=count+1;
end
//break;
end
end
for (j=0,i = lead; i < 8; i = i +1) begin
B[j]<=L[i];
j=j+1;
end
// for (i = 0; i < 8-lead; i = i + 1) begin
  //  #1 $display("Data = %h",B[i]);   
  //end
if(B[7]===1'b1)begin
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
final_stage1[15:0]<=stage1[15:0];//1
final_stage2[15:0]<=final_stage1[15:0]+stage2[15:0];//2
final_stage3[15:0]<=final_stage2[15:0]+stage3[15:0];//3
final_stage4[15:0]<=final_stage3[15:0]+stage4[15:0];//4
final_stage5[15:0]<=final_stage4[15:0]+stage5[15:0];//5

C[15:0]<=final_stage5[15:0];//correct answer  
end


endmodule
