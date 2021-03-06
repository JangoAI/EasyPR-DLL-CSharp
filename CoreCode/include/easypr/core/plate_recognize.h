//////////////////////////////////////////////////////////////////////////
// Name:	    plate_recognize Header
// Version:		1.0
// Date:	    2014-09-28
// Author:	    liuruoze
// Copyright:   liuruoze
// Reference:	Mastering OpenCV with Practical Computer Vision Projects
// Reference:	CSDN Bloger taotao1233
// Desciption:
// Defines CPlateRecognize
//////////////////////////////////////////////////////////////////////////
#ifndef EASYPR_CORE_PLATERECOGNIZE_H_
#define EASYPR_CORE_PLATERECOGNIZE_H_

#include "easypr/core/plate_detect.h"
#include "easypr/core/chars_recognise.h"

/*! \namespace easypr
Namespace where all the C++ EasyPR functionality resides
*/
namespace easypr {

  class CPlateRecognize : public CPlateDetect, public CCharsRecognise {
  public:
    CPlateRecognize();

    int plateRecognize(Mat src, std::vector<CPlate> &plateVec, const int show_type, int img_index = 0);
    int plateRecognize(Mat src, std::vector<std::string> &licenseVec);
    int plateRecognize(Mat src, std::vector<CPlate> &plateVec, int img_index, Mat& output, const vector<CPlate>& plateVecGT);

    int plateRecognizeAsText(Mat src, std::vector<CPlate> &licenseVec);
    int plateRecognizeAsTextNM(Mat src, std::vector<CPlate> &licenseVec);

    inline void setLifemode(bool param) { CPlateDetect::setPDLifemode(param); }
    inline void setDetectType(int param) { CPlateDetect::setDetectType(param); }

    inline void setResultShow(bool param) { m_showResult = param; }
    inline bool getResultShow() const { return m_showResult; }

    inline void setDetectShow(bool param) { CPlateDetect::setDetectShow(param); }
    inline void setDebug(bool param) { setResultShow(param); }

    void LoadSVM(std::string path);
    void LoadANN(std::string path);
    void LoadChineseANN(std::string path);

  private:
    // show the detect and recognition result image
    bool m_showResult;
  };

} /* \namespace easypr  */

#endif  // EASYPR_CORE_PLATERECOGNIZE_H_