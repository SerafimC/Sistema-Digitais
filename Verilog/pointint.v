module Area(
	input signed [11:0] ax, input signed [11:0] ay,// 32, 51
	input signed [11:0] bx, input signed [11:0] by,// 0, 0
	input signed [11:0] cx, input signed [11:0] cy,// 69, 54
	output signed [82:0] out
);
	//(((m1) - (m2)) + ((m3) - (m4)) + ((m5) - (m6)));
	wire signed [12:0] m1;// 0
	wire signed [12:0] m2;// 0
	wire signed [12:0] m3;// 3519
	wire signed [12:0] m4;// 1728
	wire signed [12:0] m5;// 0
	wire signed [12:0] m6;// 0

	wire signed [23:0] s1;
	wire signed [23:0] s2;
	wire signed [23:0] s3;
	
	wire signed [82:0] sumf;

	assign m1 = ax * by;
	assign m2 = ay * bx;
	assign m3 = ay * cx;	

	assign m4 = ax * cy;
	assign m5 = bx * cy;
	assign m6 = by * cx;

	assign s1 = m1 - m2; 
	assign s2 = m3 - m4;
	assign s3 = m5 - m6;

	assign sumf = s1 + s2 + s3;
	
	assign out = sumf;

endmodule

module isintriangule(
	input signed [11:0] px,
	input signed [11:0] py,
	input signed [11:0] ax,
	input signed [11:0] ay,
	input signed [11:0] bx,
	input signed [11:0] by,
	input signed [11:0] cx,
	input signed [11:0] cy,
	output signed out
);
	wire signed [82:0] b1;
	wire signed [82:0] b2;
	wire signed [82:0] b3;

	Area A1(px, py, bx, by, cx, cy, b1);
	Area A2(ax, ay, px, py, cx, cy, b2);
	Area A3(ax, ay, bx, by, px, py, b3);

	assign out = (b1 > 0) && (b2 > 0) && (b3 > 0);

endmodule

module principal;

	integer signed input_file;
	integer	signed output_file;

	reg signed [90:0] value;

	reg signed [11:0] ax; reg signed [11:0] ay;
	reg signed [11:0] bx; reg signed [11:0] by;
	reg signed [11:0] cx; reg signed [11:0] cy;
	reg signed [11:0] px; reg signed [11:0] py;
	reg signed [11:0] r;
	

	isintriangule A(px, py, ax, ay, bx, by, cx, cy, out);

	initial begin
		$dumpvars(0, A);		
	
		input_file  = $fopen("Result.txt", "r");
		output_file = $fopen("Result_verilog.txt", "w");

		if(input_file == 0) begin
			$display("Cannot open input_file. Does it exists?");
			$finish;
		end
	end

	always #2 begin
		if(!$feof(input_file)) begin			
			value = $fscanf(input_file, "A(%d, %d),  B(%d, %d), C(%d, %d),  P(%d, %d) = %d\n", ax, ay, bx, by, cx, cy, px, py, r);
			#1			
			$fwrite(output_file, "A(%0d, %0d),  B(%0d, %0d), C(%0d, %0d),  P(%0d, %0d) = %0d\n", ax, ay, bx, by, cx, cy, px, py, out);
		end
		else begin
			$finish;
		end
	end

endmodule


