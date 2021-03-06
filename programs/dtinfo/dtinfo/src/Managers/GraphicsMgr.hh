/*
 * $XConsortium: GraphicsMgr.hh /main/10 1996/11/12 10:14:04 cde-hal $
 *
 * Copyright (c) 1992 HaL Computer Systems, Inc.  All rights reserved.
 * UNPUBLISHED -- rights reserved under the Copyright Laws of the United
 * States.  Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 * 
 * This software contains confidential information and trade secrets of HaL
 * Computer Systems, Inc.  Use, disclosure, or reproduction is prohibited
 * without the prior express written permission of HaL Computer Systems, Inc.
 * 
 *                         RESTRICTED RIGHTS LEGEND
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(l)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 *                        HaL Computer Systems, Inc.
 *                  1315 Dell Avenue, Campbell, CA  95008
 * 
 */

#include "UAS.hh"

// Arg, this shouldn't be here... 
//#include <X11/Intrinsic.h>  

class PixmapGraphic;
class DetachGraphic;


#if defined(SVR4) || defined(hpux)
#define pid_type pid_t 
#else
#define pid_type int
#endif

class Graphic;

class GraphicsMgr : public Long_Lived,
                    public UAS_Sender<DetachGraphic>,
                    public UAS_Sender<ReAttachGraphic>
{
friend class Graphic;
public: // functions
  GraphicsMgr();
  ~GraphicsMgr();

  //Graphic* get(UAS_Pointer<UAS_Common> &, const char *locator);
  UAS_Pointer<Graphic> get(UAS_Pointer<UAS_Common> &, const char *locator);

  // called by ViewportAgent
  void detach (UAS_Pointer<UAS_Common> &, UAS_Pointer<Graphic> &); 

  void uncache(Graphic*);
  GraphicAgent* get_agent(UAS_String &);
  void add_detached(GraphicAgent*);
  void remove_detached(GraphicAgent*);
  bool is_detached(UAS_Pointer<Graphic> &);
  void init_gr(UAS_Pointer<Graphic> &);
  PixmapGraphic *detached_graphic();
  void reattach_graphic(UAS_Pointer<Graphic> &);


private:
  // called only from Graphic to fill it in 
  PixmapGraphic *get_graphic (UAS_Pointer<Graphic> &gr);
  PixmapGraphic *get_graphic (const UAS_String &, unsigned int, const UAS_String&, unsigned short);


  PixmapGraphic *find(const UAS_Pointer<Graphic> &);

private: // variables

  xList<Graphic * >	  f_graphic_cache ;
  xList<GraphicAgent * >  f_detached_list ; // list of detached graphics

private:
  LONG_LIVED_HH(GraphicsMgr,graphics_mgr);
};

//
//  Now (as of CDE development), instead of using the Graphic class
//  (which was changed to UAS_EmbeddedObject), we use this Graphic
//  class. This class implements stuff that used to be implemented
//  at the UAS layer, and wraps an embedded object for the other
//  calls. The stuff not implemented as pass-through here used to
//  be implemented in the UAS but didn't belong there.
//

class Graphic: public UAS_Base {
    public:
	Graphic (UAS_Pointer<UAS_Common> &, const UAS_String &);
	~Graphic ();

    public:
	unsigned int is_detached () const { return fDetached; }
	void set_detached (unsigned int flag) { fDetached = flag; }
	PixmapGraphic *graphic () {
	    return is_detached () ? detached_graphic() : pixmap_graphic();
	}
	PixmapGraphic *pixmap_graphic ();
	PixmapGraphic *pixmap_graphic (UAS_String&, unsigned int, UAS_String&, unsigned short);
	PixmapGraphic *detached_graphic();

	//
	//  Pass-throughs for UAS_EmbeddedObject (and all of its
	//  super classes .. argh).
	//
	unsigned int width () { return fObj->width (); }
	unsigned int height () { return fObj->height (); }
	UAS_String data () { return fObj->data (); }
	unsigned int data_length () { return fObj->data_length(); }
	UAS_RetrievalStatus retrieve () { return fObj->retrieve(); }
	UAS_RetrievalStatus retrieval_status () {
		return fObj->retrieval_status();
	}
	void cancel_retrieval () { fObj->cancel_retrieval (); }
	void flush () { fObj->flush(); }
	UAS_String locator ();
	UAS_String content_type();
	UAS_String title ();
	UAS_String id ();
	UAS_ObjectType type () { return fObj->type (); }

	unsigned int llx () { return fObj->llx(); }
	unsigned int lly () { return fObj->lly(); }
	unsigned int urx () { return fObj->urx(); }
	unsigned int ury () { return fObj->ury(); }

	void set_agent(GraphicAgent *agent) { fagent = agent; }
        GraphicAgent *get_agent() { return fagent; }

    private:
	unsigned int			fDetached;
	PixmapGraphic *			fPixmap;
	PixmapGraphic *			fDetachedPixmap;
	UAS_Pointer<UAS_EmbeddedObject> fObj;

   	GraphicAgent 		       *fagent;
};
