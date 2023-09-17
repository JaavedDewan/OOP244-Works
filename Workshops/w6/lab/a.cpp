#include <iostream>

#include <fstream>

#include <string>

#include <cstring>

#include "TextFile.h"

#include "cstring.h"

using namespace std;

namespace sdds {

	Line::operator const char* () const {

		return (const char*)m_value;

	}

	Line& Line::operator=(const char* lineValue) {

		delete[] m_value;

		m_value = new char[lineValue == nullptr ? 0 : strlen(lineValue) + 1];

		strcpy(m_value, lineValue);

		return *this;

	}

	Line::~Line() {

		delete[] m_value;

	}

	void TextFile::setEmpty() {

		delete[] m_textLines;

		m_textLines = nullptr;

		delete[] m_filename;

		m_filename = nullptr;

		m_noOfLines = 0;

	}

	void TextFile::setFilename(const char* fname, bool isCopy) {

		delete[] m_filename;

		if (!isCopy) {

			m_filename = new char[fname == nullptr ? 0 : strlen(fname) + 1];

			strcpy(m_filename, fname);

			return;

		}

		m_filename = new char[fname == nullptr ? 0 : strLen(fname) + 3];

		string copy_name = "C_";

		for (int i = 0; i < (int)strlen(fname); i++)

			copy_name += fname[i];

		strcpy(m_filename, copy_name.c_str());

	}

	void TextFile::setNoOfLines() {

		int cnt = 0;

		ifstream in;

		in.open(m_filename);

		string line;

		while (getline(in, line))

			cnt++;

		in.close();

		if (!cnt) {

			delete[] m_filename;

			m_filename = nullptr;

			m_noOfLines = 0;

			return;

		}

		m_noOfLines = cnt;

	}

	void TextFile::loadText() {

		delete[] m_textLines;

		if (m_filename == nullptr) return;

		m_textLines = new Line[m_noOfLines];

		ifstream in;

		in.open(m_filename);

		if (in.is_open()) {

			string line;

			for (int i = 0; i < (int)m_noOfLines; i++) {

				getline(in, line);

				m_textLines[i] = line.c_str();

			}

		}

		in.close();

	}

	void TextFile::saveAs(const char* fileName) const {

		if (fileName == nullptr) return;

		ofstream _out;

		_out.open(fileName);

		if (_out.is_open())

			for (int i = 0; i < (int)m_noOfLines; i++)

				_out << m_textLines[i] << '\n';

		_out.close();

	}

	TextFile::TextFile(unsigned int pageSize) {

		m_pageSize = pageSize;

		this->m_filename = nullptr;

		this->m_textLines = nullptr;

		this->m_noOfLines = 0;

	}

	TextFile::TextFile(const char* filename, unsigned int pageSize) {

		m_pageSize = pageSize;

		this->m_filename = nullptr;

		this->m_textLines = nullptr;

		this->m_noOfLines = 0;

		if (filename != nullptr) {

			setFilename(filename);

			setNoOfLines();

			loadText();

		}

	}

	void TextFile::safe() {

		this->m_filename = nullptr;

		this->m_textLines = nullptr;

		this->m_noOfLines = 0;

	}

	TextFile::TextFile(const TextFile& _text) {

		m_pageSize = _text.m_pageSize;

		this->m_filename = nullptr;

		this->m_textLines = nullptr;

		this->m_noOfLines = 0;

		setFilename(_text.m_filename, true);

		_text.saveAs(m_filename);

		setNoOfLines();

		loadText();

	}

	TextFile& TextFile::operator=(const TextFile& _text) {

		if (this == &_text) return *this;

		delete[] this->m_textLines;

		m_textLines = nullptr;

		_text.saveAs(m_filename);

		setNoOfLines();

		loadText();

		return *this;

	}

	TextFile::~TextFile() {

		delete[] this->m_filename;

		delete[] this->m_textLines;

	}

	unsigned TextFile::lines() const {

		return m_noOfLines;

	}

	std::ostream& TextFile::view(ostream& ostr) const {

		if (!*this) return ostr;

		ostr << m_filename << endl;

		ostr.width(m_filename == nullptr ? 0 : strLen(m_filename) - 1);

		ostr.fill('=');

		ostr << "" << endl;

		for (int i = 0; i < (int)m_noOfLines; i++) {

			if (!(i % m_pageSize) && i) {

				ostr << "Hit ENTER to continue...";

				cin.get();

			}

			ostr << m_textLines[i].m_value << endl;

		}

		return ostr;

	}

	std::istream& TextFile::getFile(istream& istr) {

		string a;

		istr >> a;

		while (getchar() != '\n');

		setFilename(a.c_str());

		setNoOfLines();

		loadText();

		return istr;

	}

	const char* TextFile::operator[](unsigned int index) const {

		if (m_textLines == nullptr) return nullptr;

		return m_textLines[index % m_noOfLines];

	}

	TextFile::operator bool() const {

		return !(this->m_textLines == nullptr || this->m_filename == nullptr || !this->m_noOfLines);

	}

	const char* TextFile::name() const {

		return m_filename;

	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {

		text.view(ostr);

		return ostr;

	}

	std::istream& operator>>(std::istream& istr, TextFile& text) {

		text.getFile(istr);

		return istr;

	}

}