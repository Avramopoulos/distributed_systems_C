struct Y_array {
	int y_array <100>;
	int y_size;
};

struct prod_array {
	int y_array <100>;
	int y_size;
	float a;
};

struct max_min {
	int max;
	int min;
};

struct aY {
	float prod <100>;
};
program ASK1 {
		version ASK1_VERS {
			float AVG(Y_array) = 1;
			max_min MAX_MIN(Y_array) = 2;
			aY MUL(prod_array) = 3;
	} = 1;
} = 0x23451111;

