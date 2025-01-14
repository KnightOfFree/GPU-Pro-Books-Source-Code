//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//  Scene Graph 3D                                                          //
//  Georgios Papaioannou, 2009                                              //
//                                                                          //
//  This is a free, extensible scene graph management library that works    //
//  along with the EaZD deferred renderer. Both libraries and their source  //
//  code are free. If you use this code as is or any part of it in any kind //
//  of project or product, please acknowledge the source and its author.    //
//                                                                          //
//  For manuals, help and instructions, please visit:                       //
//  http://graphics.cs.aueb.gr/graphics/                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef _SCENE_GRAPH_LINEARMOTION3D_
#define _SCENE_GRAPH_LINEARMOTION3D_

#include <libxml/tree.h>

#include "cglib.h"
#include "SceneGraph_TransformationNode3D.h"
#include "SceneGraph_Timer3D.h"

#define SCENE_GRAPH_MOTION_ONEWAY   1
#define SCENE_GRAPH_MOTION_PINGPONG 2

class LinearMotion3D: public TransformNode3D
{
	protected:
		Timer3D timer;

		float repeats_init, repeats;
		float duration_init, duration;

		Vector3D begin, begin_init;
		Vector3D end, end_init;

		float interp;
		int mode;

		static vector<char *> eventmap;
		virtual int getEventID (char * eventname) GET_EVENT_ID(eventname)

	public:
		LinearMotion3D();
		~LinearMotion3D();

		void setBegin(Vector3D b) { begin = b; }
		void setEnd(Vector3D b) { end = b; }
		void setDuration(float d) { duration = d; }
		void setMotionType(int t) { mode = t; }
		void setRepeats(float r) { repeats = r; }
		Vector3D getPosition() { return TransformNode3D::offset; }

		virtual void app();
		virtual void parse(xmlNodePtr pXMLnode);
		virtual void processMessage(char * msg);
		virtual void init();
		virtual void reset();
		static void registerEvent(char *evt) {eventmap.push_back(evt);}
};

#endif

