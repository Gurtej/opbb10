/*
 
 Copyright (c) 2013, SMB Phone Inc.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */
 
#ifndef _HF_CONTACT_
#define _HF_CONTACT_

#include <hookflash/core/IContact.h>

#include <vector>

namespace hookflash {
  namespace blackberry {

    class Contact {
    public:
      typedef hookflash::core::IContactPtr IContactPtr;

    public:
      Contact(
              const std::string& fullName,
              const std::string& id,
              const std::string& pictureUrl,
              const std::string& identityURI
              );

      std::string GetFullName() const { return mFullName; }
      std::string GetId() const { return mId; }
      std::string GetPictureUrl() const { return mPictureUrl; }
      std::string GetIdentityURI() const { return mIdentityURI; }

      IContactPtr GetContact() const { return mContact; }
      void SetContact(IContactPtr contact) { mContact = contact; }

    private:

      std::string mFullName;
      std::string mId;
      std::string mPictureUrl;
      std::string mIdentityURI;

      IContactPtr mContact;
    };
  }
}

#endif // _HF_CONTACT_