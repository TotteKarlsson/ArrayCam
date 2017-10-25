#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.StdActns.hpp>
#include <ComCtrls.hpp>

#include <fstream>
#include <tchar.h>
#include <string>
#include <memory>
#include <windows.h>
//#include <functional>


#include "Poco/Process.h"
#include "Poco/PipeStream.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/Timespan.h"

#include "mtkWin32Utils.h"
#include "mtkLogFileReader.h"
#include "mtkLogger.h"
#include "mtkUtils.h"
#include "atVCLUtils.h"
#include "mtkFloatLabel.h"
#include "mtkIniFile.h"
#include "mtkIniFileProperties.h"
#include "mtkFileUtils.h"
#include "mtkMathUtils.h"

//#include "mtkThread.h"

#include "TIntLabel.h"
#include "TIntegerLabeledEdit.h"
#include "TPropertyCheckBox.h"
#include "TRegistryForm.h"
#include "TSTDStringLabeledEdit.h"

