#include "StandardFilesystemDriver.h"
#include <filesystem>
#include <fstream>


Winter::Drivers::Impl::StandardFilesystem::StandardFilesystem()
{}

void Winter::Drivers::Impl::StandardFilesystem::fsInit()
{}

std::optional<std::vector<char>> 
Winter::Drivers::Impl::StandardFilesystem::fsGet(std::string p)
{
	namespace fs = std::filesystem;

	std::optional<std::vector<char>> r;

	if(!fs::exists(p) || fs::is_directory(p) || fs::is_block_file(p))
		return r;

	const size_t size = fs::file_size(p);

	std::vector<char> content(size);

	std::ifstream in(p, std::ios::binary);
	in.read(content.data(), size);
	in.close();

	r = content;

	return r;
}

bool Winter::Drivers::Impl::StandardFilesystem::fsWrite
(std::vector<char> s, std::string p)
{
	namespace fs = std::filesystem;

	if(fs::path(p).has_parent_path()){
		if (!fs::exists(fs::path(p).parent_path())) {
			fs::create_directories(fs::path(p).parent_path());
		}
	}

	if (fs::exists(p)) {
		if (fs::is_directory(p) || fs::is_block_file(p)) return false;
	}
	
	std::ofstream out(p, std::ios::binary);
	out.write(s.data(), s.size());
	out.close();

	return true;
}

void Winter::Drivers::Impl::StandardFilesystem::fsDestroy()
{}

Winter::Drivers::Impl::StandardFilesystem::~StandardFilesystem()
{}
