#include<iostream>
#include<fstream>
#include <cppcodec/base64_rfc4648.hpp>
#include <string>
#include <sstream>





using base64 = cppcodec::base64_rfc4648;
using namespace std;


int main()
{
	cout << "Base-64 Example ! " << endl;

	std::vector<uint8_t> decoded = base64::decode("YW55IGNhcm5hbCBwbGVhc3VyZQ==");
  	std::cout << "decoded size (\"any carnal pleasure\"): " << decoded.size() << '\n';
  	std::cout << base64::encode(decoded) << std::endl; // "C5Q7J833C5S6WRBC41R6RSB1EDTQ4S8"

  	std::ifstream t("in.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();
	string in_file_str = buffer.str();

	ifstream input( "in.txt", std::ios::binary );
	std::vector<unsigned char> buffer_in_file(std::istreambuf_iterator<char>(input), {});

	cout << "IN FILE STR :: " << in_file_str << endl;

	cout << "buffer_in_file SIZE :: " << buffer_in_file.size() << endl;

	string encode_str_file = base64::encode(buffer_in_file);

	cout << "ENCODED :: " << endl;

	cout << encode_str_file << endl;

	// Reference Link : https://stackoverflow.com/questions/5420317/reading-and-writing-binary-file

	std::vector<unsigned char> buffer_out(encode_str_file.begin(),encode_str_file.end());

	vector<uint8_t> decoded_str_file = base64::decode(buffer_out);

	cout << "decoded_str_file Size :: " << decoded_str_file.size();

	ofstream fout("out.txt", ios::out | ios::binary);
 	fout.write((char*)&decoded_str_file[0], decoded_str_file.size() * sizeof(decoded_str_file));
 	fout.close();

	//std::ofstream output( "out.txt", std::ios::binary );
	//for(auto a : decoded_str_file)
	// {
	// 	output.write(a,sizeof(uint8_t));

	// }
	

	//output.close();







	return 0;
}