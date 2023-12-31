/*
 * Copyright 2009-2011, Michael Lotz, mmlr@mlotz.ch.
 * Distributed under the terms of the MIT License.
 */
#ifndef HID_REPORT_ITEM_H
#define HID_REPORT_ITEM_H

#include <SupportDefs.h>

class HIDReport;

class HIDReportItem {
public:
								HIDReportItem(HIDReport *report,
									uint32 bitOffset, uint8 bitLength,
									bool hasData, bool isArray, bool isRelative,
									uint32 minimum, uint32 maximum,
									uint32 usage);

		HIDReport *				Report() { return fReport; };

		bool					HasData() { return fHasData; };
		bool					Relative() { return fRelative; };
		bool					Array() { return fArray; };
		bool					Signed() { return fMinimum > fMaximum; };
		uint32					Minimum() { return fMinimum; }

		uint16					UsagePage();
		uint16					UsageID();

		uint32					Usage() { return fUsage; };

		status_t				Extract();
		status_t				Insert();

		status_t				SetData(uint32 data);
		uint32					Data() { return fData; };

		uint32					ScaledData(uint8 scaleToBits, bool toBeSigned);
		uint32					ScaledRangeData(uint32 minimum, uint32 maximum);
		float					ScaledFloatData();

		bool					Valid() { return fValid; };

		void					PrintToStream(uint32 indentLevel = 0);
private:
		HIDReport *				fReport;
		uint32					fByteOffset;
		uint8					fShift;
		uint32					fMask;
		uint8					fBitCount;
		uint8					fByteCount;
		bool					fHasData;
		bool					fArray;
		bool					fRelative;
		uint32					fMinimum;
		uint32					fMaximum;
		uint32					fUsage;

		uint32					fData;
		bool					fValid;
};

#endif // HID_REPORT_ITEM_H
