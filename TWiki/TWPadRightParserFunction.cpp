//
//  TWPadRightParserFunction.cpp
//  XTBook
//
//  Created by Kawada Tomoaki on 7/26/11.
//  Copyright 2011 Nexhawks. All rights reserved.
//
/*
 * This file is part of XTBook.
 *
 * XTBook is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * XTBook is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with XTBook.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "TWUtils.h"
#include "TWPadRightParserFunction.h"

std::wstring TWPadRightParserFunction::execute(const std::wstring& arg0, const std::vector<std::wstring>& args, TWPreprocessorFrame *){
	if(args.size()<1){
		throw std::wstring(L"too few arguments for padleft.");
	}
	
	std::wstring padText=L"0";
	if(args.size()>=2)
		padText=args[1];
	
	if(padText.empty())
		return arg0;
	
	size_t goalLength=(size_t)TWUtils::intValueFromString(args[0]);
	std::wstring out=arg0;
	std::wstring padding;
	
	while(out.size()+padding.size()<goalLength){
		size_t neededLength=goalLength-out.size()-padding.size();
		if(neededLength>padText.size())
			neededLength=padText.size();
		
		padding.append(padText, 0, neededLength);
	}
	
	return out+padding;
	
}