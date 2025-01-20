// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TbasicScintillatorDataDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "TbasicScintillatorData.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TbasicScintillatorData(void *p = nullptr);
   static void *newArray_TbasicScintillatorData(Long_t size, void *p);
   static void delete_TbasicScintillatorData(void *p);
   static void deleteArray_TbasicScintillatorData(void *p);
   static void destruct_TbasicScintillatorData(void *p);
   static void streamer_TbasicScintillatorData(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TbasicScintillatorData*)
   {
      ::TbasicScintillatorData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TbasicScintillatorData >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TbasicScintillatorData", ::TbasicScintillatorData::Class_Version(), "TbasicScintillatorData.h", 37,
                  typeid(::TbasicScintillatorData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TbasicScintillatorData::Dictionary, isa_proxy, 16,
                  sizeof(::TbasicScintillatorData) );
      instance.SetNew(&new_TbasicScintillatorData);
      instance.SetNewArray(&newArray_TbasicScintillatorData);
      instance.SetDelete(&delete_TbasicScintillatorData);
      instance.SetDeleteArray(&deleteArray_TbasicScintillatorData);
      instance.SetDestructor(&destruct_TbasicScintillatorData);
      instance.SetStreamerFunc(&streamer_TbasicScintillatorData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TbasicScintillatorData*)
   {
      return GenerateInitInstanceLocal(static_cast<::TbasicScintillatorData*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TbasicScintillatorData*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TbasicScintillatorData::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TbasicScintillatorData::Class_Name()
{
   return "TbasicScintillatorData";
}

//______________________________________________________________________________
const char *TbasicScintillatorData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorData*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TbasicScintillatorData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorData*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TbasicScintillatorData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorData*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TbasicScintillatorData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorData*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TbasicScintillatorData::Streamer(TBuffer &R__b)
{
   // Stream an object of class TbasicScintillatorData.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_E_DetectorNbr;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            unsigned short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_E_StripNbr;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            unsigned short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<Double_t> &R__stl =  fbasicScintillator_Energy;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_T_DetectorNbr;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            unsigned short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_T_StripNbr;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            unsigned short R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<Double_t> &R__stl =  fbasicScintillator_Time;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            double R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      {
         vector<Int_t> &R__stl =  fbasicScintillator_EventID;
         R__stl.clear();
         int R__i, R__n;
         R__b >> R__n;
         R__stl.reserve(R__n);
         for (R__i = 0; R__i < R__n; R__i++) {
            int R__t;
            R__b >> R__t;
            R__stl.push_back(R__t);
         }
      }
      R__b.CheckByteCount(R__s, R__c, TbasicScintillatorData::IsA());
   } else {
      R__c = R__b.WriteVersion(TbasicScintillatorData::IsA(), kTRUE);
      TObject::Streamer(R__b);
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_E_DetectorNbr;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<UShort_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_E_StripNbr;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<UShort_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<Double_t> &R__stl =  fbasicScintillator_Energy;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<Double_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_T_DetectorNbr;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<UShort_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<UShort_t> &R__stl =  fbasicScintillator_T_StripNbr;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<UShort_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<Double_t> &R__stl =  fbasicScintillator_Time;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<Double_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<Int_t> &R__stl =  fbasicScintillator_EventID;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<Int_t>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TbasicScintillatorData(void *p) {
      return  p ? new(p) ::TbasicScintillatorData : new ::TbasicScintillatorData;
   }
   static void *newArray_TbasicScintillatorData(Long_t nElements, void *p) {
      return p ? new(p) ::TbasicScintillatorData[nElements] : new ::TbasicScintillatorData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TbasicScintillatorData(void *p) {
      delete (static_cast<::TbasicScintillatorData*>(p));
   }
   static void deleteArray_TbasicScintillatorData(void *p) {
      delete [] (static_cast<::TbasicScintillatorData*>(p));
   }
   static void destruct_TbasicScintillatorData(void *p) {
      typedef ::TbasicScintillatorData current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TbasicScintillatorData(TBuffer &buf, void *obj) {
      ((::TbasicScintillatorData*)obj)->::TbasicScintillatorData::Streamer(buf);
   }
} // end of namespace ROOT for class ::TbasicScintillatorData

namespace ROOT {
   static TClass *vectorlEunsignedsPshortgR_Dictionary();
   static void vectorlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPshortgR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPshortgR(void *p);
   static void deleteArray_vectorlEunsignedsPshortgR(void *p);
   static void destruct_vectorlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned short>*)
   {
      vector<unsigned short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned short>", -2, "vector", 389,
                  typeid(vector<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned short>) );
      instance.SetNew(&new_vectorlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPshortgR);
      instance.SetDelete(&delete_vectorlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned short>","std::vector<unsigned short, std::allocator<unsigned short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr))->GetClass();
      vectorlEunsignedsPshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPshortgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned short> : new vector<unsigned short>;
   }
   static void *newArray_vectorlEunsignedsPshortgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned short>[nElements] : new vector<unsigned short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPshortgR(void *p) {
      delete (static_cast<vector<unsigned short>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPshortgR(void *p) {
      delete [] (static_cast<vector<unsigned short>*>(p));
   }
   static void destruct_vectorlEunsignedsPshortgR(void *p) {
      typedef vector<unsigned short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned short>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 389,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 389,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace {
  void TriggerDictionaryInitialization_TbasicScintillatorDataDict_Impl() {
    static const char* headers[] = {
"TbasicScintillatorData.h",
nullptr
    };
    static const char* includePaths[] = {
"../Core",
"../Physics",
"../../Core",
"../../Physics",
"../TrackReconstruction",
"../../TrackReconstruction",
"/home/guy/software/root/root_install/include/",
"/home/guy/software/nptool/nptool/NPLib/Detectors/basicScintillator/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TbasicScintillatorDataDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$TbasicScintillatorData.h")))  TbasicScintillatorData;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TbasicScintillatorDataDict dictionary payload"

#ifndef NPMULTITHREADING
  #define NPMULTITHREADING 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TbasicScintillatorData.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TbasicScintillatorData", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TbasicScintillatorDataDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TbasicScintillatorDataDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TbasicScintillatorDataDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TbasicScintillatorDataDict() {
  TriggerDictionaryInitialization_TbasicScintillatorDataDict_Impl();
}
