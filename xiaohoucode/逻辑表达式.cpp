// char c[500005];
	// bool x[500005], is_k[1000005];
	// memset(c, ' ', sizeof(c));
	// memset(x, false, sizeof(x));
	// int cnt1 = 0, cnt2 = 0;
	// // 分门别类
	// for (int i = l; i <= r; i++){
	// 	//cout << s[i] << endl;
	// 	if (s[i] == '&') c[++cnt1] = '&';
	// 	if (s[i] == '|') c[++cnt1] = '|';
	// 	if (s[i] == '0') x[++cnt2] = false;
	// 	if (s[i] == '1') x[++cnt2] = true;
	// 	if (s[i] == '('){
	// 		int xx = 1;
	// 		while (xx > 0){
	// 			i++;
	// 			//cout << s[i] << endl;
	// 			if (s[i] == '(') xx++;
	// 			if (s[i] == ')') xx--;
	// 		}
	// 		//cout << t << ' ' << i-1 << ' '<< cnt2 << endl;
	// 		is_k[++cnt2] = true;
	// 	}
	// }
	// // 处理and
	// for (int i = 1; i <= cnt1; i++){
	// 	if (c[i] == '&'){
	// 		if (is_k[i]) x[i] = fun()
	// 		if (x[i] == false){
	// 			And++;
	// 			cout << "a+" << endl;
	// 			x[i+1] = false;
	// 		}
	// 		else x[i] = x[i+1];
	// 	}
	// }
	// cout << l << ' ' << r << endl;
	// for (int i = 1; i <= cnt1; i++){
	// 	cout << c[i] << ' ';
	// }
	// cout << endl;
	// for (int i = 1; i <= cnt2; i++){
	// 	cout << x[i] << ' ';
	// }
	// cout << endl;
	// // 处理or的同时处理*并得出答0案
	// for (int i = 1; i <= cnt1; i++){
	// 	if (c[i] == '|'){
	// 		if (x[i] == true){
	// 			Or++;
	// 			cout << "o+" << endl;
	// 			return true;
	// 		} else {
	// 			if (c[i+1] == '&') x[i+2] = x[i+1];
	// 		}
	// 	}
	// }
	// return x[cnt2];