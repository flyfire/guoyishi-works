//
ofstream& open_file(ofstream &out, const string &file)
{
	out.close();
	out.clear();
	out.open(file.c_str());
	return out;
}