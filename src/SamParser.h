/**
 * Contact: philipp.rescheneder@gmail.com
 */

#ifndef SAMPARSER_H_
#define SAMPARSER_H_

#include "IParser.h"

#include <zlib.h>
#include <stdio.h>

#include "kseq.h"

int const buffer_size = 10000;

class SamParser: public IParser {

private:
	gzFile fp;
	bool parse_all;
	char *buffer;

	kseq_t * tmp;

public:

	SamParser(int const p_qryMaxLen) : IParser(p_qryMaxLen) {
		fp = 0;
		parse_all = true;
		buffer = 0;
		tmp = 0;
	}

	virtual ~SamParser() {
		if (tmp != 0) {
			kseq_destroy(tmp);
			tmp = 0;
		}
		delete[] buffer;
		buffer = 0;
		gzclose(fp);
	}

	virtual void init(char const * fileName);
	virtual int doParseRead(MappedRead * read);
//	virtual int doParseRead(SAMRecord * read);
};

#endif /* SAMPARSER_H_ */
