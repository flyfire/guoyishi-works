//
while (it != files.end()) {
	input.open(it->c_str());
	if(!input) {
		cerr << "error: can not open file: "
			<< *it << endl;
		input.clear();
		++it;
		continue;
	}

	while(input >> s)
		process(s);
	input.close();
	input.clear();
	++it;
}