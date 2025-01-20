// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TbasicScintillatorPhysicsDict
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
#include "TbasicScintillatorPhysics.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TbasicScintillatorPhysics(void *p = nullptr);
   static void *newArray_TbasicScintillatorPhysics(Long_t size, void *p);
   static void delete_TbasicScintillatorPhysics(void *p);
   static void deleteArray_TbasicScintillatorPhysics(void *p);
   static void destruct_TbasicScintillatorPhysics(void *p);
   static void streamer_TbasicScintillatorPhysics(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TbasicScintillatorPhysics*)
   {
      ::TbasicScintillatorPhysics *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TbasicScintillatorPhysics >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TbasicScintillatorPhysics", ::TbasicScintillatorPhysics::Class_Version(), "TbasicScintillatorPhysics.h", 46,
                  typeid(::TbasicScintillatorPhysics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TbasicScintillatorPhysics::Dictionary, isa_proxy, 16,
                  sizeof(::TbasicScintillatorPhysics) );
      instance.SetNew(&new_TbasicScintillatorPhysics);
      instance.SetNewArray(&newArray_TbasicScintillatorPhysics);
      instance.SetDelete(&delete_TbasicScintillatorPhysics);
      instance.SetDeleteArray(&deleteArray_TbasicScintillatorPhysics);
      instance.SetDestructor(&destruct_TbasicScintillatorPhysics);
      instance.SetStreamerFunc(&streamer_TbasicScintillatorPhysics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TbasicScintillatorPhysics*)
   {
      return GenerateInitInstanceLocal(static_cast<::TbasicScintillatorPhysics*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TbasicScintillatorPhysics*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TbasicScintillatorPhysics::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TbasicScintillatorPhysics::Class_Name()
{
   return "TbasicScintillatorPhysics";
}

//______________________________________________________________________________
const char *TbasicScintillatorPhysics::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorPhysics*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TbasicScintillatorPhysics::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorPhysics*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TbasicScintillatorPhysics::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorPhysics*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TbasicScintillatorPhysics::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TbasicScintillatorPhysics*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TbasicScintillatorPhysics::Streamer(TBuffer &R__b)
{
   // Stream an object of class TbasicScintillatorPhysics.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      //This works around a msvc bug and should be harmless on other platforms
      typedef NPL::VDetector baseClass0;
      baseClass0::Streamer(R__b);
      {
         vector<int> &R__stl =  DetectorNumber;
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
      {
         vector<int> &R__stl =  StripNumber;
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
      {
         vector<double> &R__stl =  Energy;
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
         vector<double> &R__stl =  Time;
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
         vector<int> &R__stl =  EventID;
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
      R__b.CheckByteCount(R__s, R__c, TbasicScintillatorPhysics::IsA());
   } else {
      R__c = R__b.WriteVersion(TbasicScintillatorPhysics::IsA(), kTRUE);
      TObject::Streamer(R__b);
      //This works around a msvc bug and should be harmless on other platforms
      typedef NPL::VDetector baseClass0;
      baseClass0::Streamer(R__b);
      {
         vector<int> &R__stl =  DetectorNumber;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  StripNumber;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<double> &R__stl =  Energy;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<double> &R__stl =  Time;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<double>::iterator R__k;
            for (R__k = R__stl.begin(); R__k != R__stl.end(); ++R__k) {
            R__b << (*R__k);
            }
         }
      }
      {
         vector<int> &R__stl =  EventID;
         int R__n=int(R__stl.size());
         R__b << R__n;
         if(R__n) {
            vector<int>::iterator R__k;
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
   static void *new_TbasicScintillatorPhysics(void *p) {
      return  p ? new(p) ::TbasicScintillatorPhysics : new ::TbasicScintillatorPhysics;
   }
   static void *newArray_TbasicScintillatorPhysics(Long_t nElements, void *p) {
      return p ? new(p) ::TbasicScintillatorPhysics[nElements] : new ::TbasicScintillatorPhysics[nElements];
   }
   // Wrapper around operator delete
   static void delete_TbasicScintillatorPhysics(void *p) {
      delete (static_cast<::TbasicScintillatorPhysics*>(p));
   }
   static void deleteArray_TbasicScintillatorPhysics(void *p) {
      delete [] (static_cast<::TbasicScintillatorPhysics*>(p));
   }
   static void destruct_TbasicScintillatorPhysics(void *p) {
      typedef ::TbasicScintillatorPhysics current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TbasicScintillatorPhysics(TBuffer &buf, void *obj) {
      ((::TbasicScintillatorPhysics*)obj)->::TbasicScintillatorPhysics::Streamer(buf);
   }
} // end of namespace ROOT for class ::TbasicScintillatorPhysics

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
  void TriggerDictionaryInitialization_TbasicScintillatorPhysicsDict_Impl() {
    static const char* headers[] = {
"TbasicScintillatorPhysics.h",
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
#line 1 "TbasicScintillatorPhysicsDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$TbasicScintillatorPhysics.h")))  TbasicScintillatorPhysics;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TbasicScintillatorPhysicsDict dictionary payload"

#ifndef NPMULTITHREADING
  #define NPMULTITHREADING 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TbasicScintillatorPhysics.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TbasicScintillatorPhysics", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TbasicScintillatorPhysicsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TbasicScintillatorPhysicsDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TbasicScintillatorPhysicsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TbasicScintillatorPhysicsDict() {
  TriggerDictionaryInitialization_TbasicScintillatorPhysicsDict_Impl();
}
