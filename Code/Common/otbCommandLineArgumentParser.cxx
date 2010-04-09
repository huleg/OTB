/*=========================================================================

  Program:   ORFEO Toolbox
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
  See OTBCopyright.txt for details.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "otbCommandLineArgumentParser.h"
#include "itkMacro.h"

#include <assert.h>
#include <iostream>
#include "otbConfigure.h" // For OTB_VERSION_STRING generated by ccmake

namespace otb
{

// --------- CommandLineArgumentParseResult  ----------------------------------------
void CommandLineArgumentParseResult
::PrintSelf(std::ostream& /*os*/ /*, itk::Indent indent*/) const
{

}

bool CommandLineArgumentParseResult
::IsOptionPresent(std::string option) const
{
  return (m_OptionMap.find(option) != m_OptionMap.end());
}

bool CommandLineArgumentParseResult
::IsOptionInputImagePresent(void) const
{
  return (this->IsOptionPresent("--InputImage"));
}
bool CommandLineArgumentParseResult
::IsOptionOutputImagePresent(void) const
{
  return (this->IsOptionPresent("--OutputImage"));
}

bool CommandLineArgumentParseResult
::IsOptionOTBTestingPresent(void) const
{
  return (this->IsOptionPresent("--OTBTesting"));
}

std::string CommandLineArgumentParseResult
::GetParameterString(std::string option, unsigned int number) const
{
  if (this->IsOptionPresent(option) == false)
    {
    itk::OStringStream msg;
    msg << "GetParameterString(): The following '" << option << "' option is unknown !!";
    CommandLineArgumentParserArgumentErrorException e(__FILE__, __LINE__);
    e.SetDescription(msg.str().c_str());
    throw e;
    }
  OptionMapType::const_iterator it = m_OptionMap.begin();
  it = m_OptionMap.find(option);
  ParameterArrayType pat = (*it).second;
  std::string        lString = pat[number];
  return (lString);
}

std::string CommandLineArgumentParseResult
::GetInputImage(void) const
{
  return (GetParameterString("--InputImage"));
}

std::string CommandLineArgumentParseResult
::GetOutputImage(void) const
{
  return (GetParameterString("--OutputImage"));
}

int CommandLineArgumentParseResult
::GetNumberOfParameters(std::string option)
{
  assert(IsOptionPresent(option));
  return (m_OptionMap[option].size());
}

void CommandLineArgumentParseResult
::Clear()
{
  m_OptionMap.clear();
}

void CommandLineArgumentParseResult
::AddOption(const std::string& option)
{
  ParameterArrayType pat;
//  pat.reserve(nParms);
  m_OptionMap[option] = pat;
}

void CommandLineArgumentParseResult
::AddParameter(const std::string& option, const std::string& parameter)
{
  m_OptionMap[option].push_back(parameter);
}

// --------- CommandLineArgumentParser  ----------------------------------------

CommandLineArgumentParser
::CommandLineArgumentParser()
{
  AddOption("--help", "Help", "-h", 0, false);
  AddOption("--version", "Version", "-v", 0, false);
  AddOptionNParams("--OTBTesting", "Testing purposes only.", "-OTBTesting", false);
  m_ProgramDescription.clear();
}

void CommandLineArgumentParser
::AddInputImage(bool obligatory)
{
  AddOption("--InputImage", "input image file name ", "-in", 1, obligatory);
}

void CommandLineArgumentParser
::AddOutputImage(bool obligatory)
{
  AddOption("--OutputImage", "output image file name ", "-out", 1, obligatory);
}

void CommandLineArgumentParser
::AddOption(std::string name, std::string comment, std::string synonim, int nParameters, bool obligatory)
{
  // Create a structure for the command
  OptionType option;
  option.CommonName  = name;
  option.Description = comment;
  option.Synonim     = synonim;
  option.NumberOfParameters = nParameters;
  option.NumberOfParametersFixed = true;
  option.Obligatory = obligatory;
  option.Finded = false;

  // Add the option to the map
  m_OptionList.push_back(option);

}

void CommandLineArgumentParser
::AddOptionNParams(std::string name, std::string comment, std::string synonim, bool obligatory)
{
  // Create a structure for the command
  OptionType option;
  option.CommonName  = name;
  option.Description = comment;
  option.Synonim     = synonim;
  option.NumberOfParameters = -1;
  option.NumberOfParametersFixed = false;
  option.Obligatory = obligatory;
  option.Finded = false;

  // Add the option to the map
  m_OptionList.push_back(option);

}

void CommandLineArgumentParser
::ParseGUI(CommandLineArgumentParseResult * /*outResult*/, bool /*failOnUnknownTrailingParameters*/)
{
  /* OTB Comment : Todo : use OTB_USE_VISU_GUI cmake option for generate this method
      Fl_Window *window = new Fl_Window(320,(m_OptionList.size()+2)*50);

      std::vector<Fl_Input*> myInputs;
      unsigned int pos = 1;
      for(ListOptionType::iterator it = m_OptionList.begin();it!=m_OptionList.end();++it,++pos)
      {
      Fl_Input * tmpInput = new Fl_Input(50,pos*50,200,30,it->CommonName.c_str());
      tmpInput->tooltip(it->Description.c_str());

    }
      Fl_Button * button = new Fl_Button(50,pos*50 , 130, 30, "Ok");
      button->tooltip("Validate parameters and exit.");
      window->end();
      window->show();
      Fl::run();

      for(std::vector<Fl_Input * >::iterator flIt =myInputs.begin();flIt!=myInputs.end();++flIt)
      {
      delete (*flIt);
    }
      delete button;
      delete window;
  */
}

void CommandLineArgumentParser
::ParseCommandLine(int argc, char *argv[],
                   CommandLineArgumentParseResult * outResult,
                   bool failOnUnknownTrailingParameters)
{
  bool tryParse = TryParseCommandLine(argc, argv, outResult, false, failOnUnknownTrailingParameters);

  bool IsHelp = outResult->IsOptionPresent("--help");
  if (IsHelp == true)
    {
    PrintUsage(std::cout);
    CommandLineArgumentParserHelpException e(__FILE__, __LINE__);
    e.SetDescription("ParseCommandLine(): Help Parser");
    throw e;
    }
  bool IsVersion = outResult->IsOptionPresent("--version");
  if (IsVersion == true)
    {
    PrintVersion(std::cout);
    CommandLineArgumentParserHelpException e(__FILE__, __LINE__);
    e.SetDescription("ParseCommandLine(): Version Parser");
    throw e;
    }
  tryParse = TryParseCommandLine(argc, argv, outResult, true, failOnUnknownTrailingParameters);
  if ((tryParse == false))
    {
    PrintUsage(std::cerr);
    CommandLineArgumentParserArgumentErrorException e(__FILE__, __LINE__);
    e.SetDescription("ParseCommandLine() argument Error");
    throw e;
    }
}

bool CommandLineArgumentParser::TryParseCommandLine(int argc, char *argv[],
                                                    CommandLineArgumentParseResult * outResult,
                                                    bool reportFailedMsg,
                                                    bool failOnUnknownTrailingParameters)
{
// Clear the result
  outResult->Clear();

  int i;
  m_ProgramName = std::string(argv[0]);
  int index(0);

// Go through the arguments
  for (i = 1; i < argc; ++i)
    {
// Get the next argument
    std::string arg(argv[i]);

    // Check if the argument is known
    bool findOption = FindOption(arg, index);
    if (findOption == false)
      {
      if (failOnUnknownTrailingParameters)
        {
        // Unknown argument found
        if (reportFailedMsg == true)
          {
          std::cerr << "The following '" << arg << "' option is unknown !!" << std::endl;
          }
        return false;
        }
      else return true;
      }
    //Check the option
    m_OptionList[index].Finded = true;
    // If the number of parameters is predefined
    if (m_OptionList[index].NumberOfParametersFixed == true)
      {
      // Check if the number of parameters is correct
      int nParameters = m_OptionList[index].NumberOfParameters;
      if (i + nParameters >= argc)
        {
        // Too few parameters
        if (reportFailedMsg == true)
          {
          std::cerr << "Missing one (or more) parameter(s) for the following '" << arg << "' option." << std::endl;
          }
        return false;
        }
      // Tell the result that the option has been encountered
      outResult->AddOption(m_OptionList[index].CommonName);

      // Pass in the parameters
      for (int j = 0; j < nParameters; ++j, ++i)
        {
        outResult->AddParameter(m_OptionList[index].CommonName, std::string(argv[i + 1]));
        }
      }
// If the number of parameters is not defined, read until the next option or the end of argv
    else
      {
// Tell the result that the option has been encountered
      outResult->AddOption(m_OptionList[index].CommonName);
      bool goOnFlag(true);
      while (goOnFlag == true)
        {
        if (argv[i + 1] != NULL)
          {
          std::string strArgv = std::string(argv[i + 1]);
          if (strArgv[0] == '-')
            {
            goOnFlag = false;
            }
          else
            {
            outResult->AddParameter(m_OptionList[index].CommonName, strArgv);
            ++i;
            }
          }
        else goOnFlag = false;
        //         ++i;
        }
      }

    }

// Check that all required arguments are specified
  for (unsigned int cpt = 0; cpt < m_OptionList.size(); cpt++)
    {
    if ((m_OptionList[cpt].Obligatory == true) && (m_OptionList[cpt].Finded == false))
      {
      // Too few parameters
      if (reportFailedMsg == true)
        {
        std::cerr << "'" << m_OptionList[cpt].CommonName << "' argument is required !!!" << std::endl;
        }
      return false;
      }
    }

// Everything is correct
  return true;
}

bool CommandLineArgumentParser::FindOption(const std::string& option, int& index)
{
  //Look through the option list
  bool         optionFoundFlag(false);
  bool         goOnFlag(true);
  unsigned int cpt(0);
  std::string  strOption(option);
  while (goOnFlag == true)
    {
    if ((m_OptionList[cpt].CommonName == strOption) || (m_OptionList[cpt].Synonim == strOption))
      {
      index = cpt;
      goOnFlag = false;
      optionFoundFlag = true;
      }
    cpt++;
    if (cpt >= m_OptionList.size())
      {
      goOnFlag = false;
      }
    }
  return (optionFoundFlag);
}

void CommandLineArgumentParser::PrintUsage(std::ostream& os) const
{
  os << std::endl;

  if (!m_ProgramDescription.empty())
    {
    os << m_ProgramDescription << std::endl << std::endl;
    }

  os << " Usage : " << m_ProgramName << std::endl;
  // Compute the max width for option display
  int          largeurmax(-1);
  unsigned int i;

  for (i = 0; i < m_OptionList.size(); ++i)
    {
    int largeur = m_OptionList[i].CommonName.size() + m_OptionList[i].Synonim.size();
    if (largeur > largeurmax) largeurmax = largeur;
    }

  // Check that all required arguments are present on the command line
  for (i = 0; i < m_OptionList.size(); ++i)
    {
    if (m_OptionList[i].CommonName != "--OTBTesting")
      {
      int largeur = m_OptionList[i].CommonName.size() + m_OptionList[i].Synonim.size();
      os << "      ";
      if (m_OptionList[i].Obligatory == false) os << "[";
      else os << " ";
      os << m_OptionList[i].CommonName;
      if (m_OptionList[i].Synonim.empty() == false)
        {
        os << "|" << m_OptionList[i].Synonim;
        }
      if (m_OptionList[i].Obligatory == false) os << "]";
      else os << " ";
//Align the text
      for (int b = largeur; b < largeurmax; b++)
        os << " ";
      os <<   "  :  " << m_OptionList[i].Description;
      if (m_OptionList[i].NumberOfParametersFixed == true)
        {
        switch (m_OptionList[i].NumberOfParameters)
          {
        case 0:
          break;
        case 1:
          os << "  (" << m_OptionList[i].NumberOfParameters << " parameter)";
          break;
        default:
          os << "  (" << m_OptionList[i].NumberOfParameters << " parameters)";
          break;
          }
        }
      else
        {
        os << "  (N parameters)";
        }
      os << std::endl;
      }
    }
  os << std::endl;
}

void CommandLineArgumentParser::PrintVersion(std::ostream& os) const
{
  os << " OTB Version : " << OTB_VERSION_STRING << std::endl;
}

}
