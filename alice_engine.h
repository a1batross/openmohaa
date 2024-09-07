typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef struct animstate_t animstate_t, *Panimstate_t;

typedef struct lerpstate_t lerpstate_t, *Plerpstate_t;

struct lerpstate_t {
    int anim;
    int frame;
    int oldanim;
    int oldframe;
    int starttime;
    float framelerp;
};

struct animstate_t {
    struct lerpstate_t base;
    struct lerpstate_t crossblend;
    int crossblend_totaltime;
    float crossblend_lerp;
    int numframes;
    int time_per_frame;
    int driven;
    int next_evaluate_time;
    int last_driven_time;
    float last_origin[3];
    float frame_delta[3];
    float frame_distance;
    float current_distance;
    int has_commands;
    int last_cmd_frame;
    int last_cmd_anim;
    int last_cmd_time;
};

typedef struct centity_t centity_t, *Pcentity_t;

typedef struct entityState_t entityState_t, *PentityState_t;

typedef struct trajectory_t trajectory_t, *Ptrajectory_t;

typedef struct bone_controller_t bone_controller_t, *Pbone_controller_t;

struct bone_controller_t {
    int bone_tag;
    float bone_angles[3];
    float bone_quat[4];
    float unknown;
};

struct trajectory_t {
    int trType;
    int trTime;
    int trDuration;
    float trBase[3];
    float trDelta[3];
};

struct entityState_t {
    int number;
    int eType;
    int eFlags;
    struct trajectory_t pos;
    struct trajectory_t apos;
    float netorigin[3];
    float origin[3];
    float origin2[3];
    float netangles[3];
    float angles[3];
    int constantLight;
    int loopSound;
    float loopSoundVolume;
    float loopSoundMinDist;
    int parent;
    int tag_num;
    int attach_use_angles; /* Created by retype action */
    float attach_offset[3]; /* Created by retype action */
    int modelindex;
    int skinNum; /* Created by retype action */
    int anim;
    int frame;
    int crossblend_time;
    int torso_anim;
    uint torso_frame;
    int torso_crossblend_time;
    struct bone_controller_t bone_controllers[5];
    byte surfaces[32];
    int clientNum;
    int groundEntityNum;
    int solid;
    float scale;
    float alpha;
    int renderfx; /* Created by retype action */
    uint rendereflags;
    int bindparent;
    float quat[4];
    float mat[3][3];
};

struct centity_t {
    struct entityState_t currentState;
    struct entityState_t nextState;
    int teleported;
    int interpolate;
    int currentValid;
    int miscTime; /* Created by retype action */
    struct animstate_t am;
    struct animstate_t torso_am;
    int errorTime;
    float errorOrigin[3];
    float errorAngles[3];
    int extrapolated;
    float rawOrigin[3];
    float rawAngles[3];
    float beamEnd[3];
    float lerpOrigin[3];
    float lerpAngles[3];
    int tikiLoopSound;
    float tikiLoopSoundVolume;
    float tikiLoopSoundMinDist;
    float color[4];
    float client_color[4];
    int client_flags;
    float something_color;
    int splash_last_spawn_time;
    int splash_still_count;
};

typedef struct cg_t cg_t, *Pcg_t;

typedef struct snapshot_t snapshot_t, *Psnapshot_t;

typedef struct playerState_t playerState_t, *PplayerState_t;

typedef struct refdef_t refdef_t, *Prefdef_t;

typedef struct refEntity_t refEntity_t, *PrefEntity_t;

typedef struct server_sound_t server_sound_t, *Pserver_sound_t;

typedef struct trace_t trace_t, *Ptrace_t;

typedef struct cplane_t cplane_t, *Pcplane_t;

typedef struct gentity_t gentity_t, *Pgentity_t;

typedef struct gclient_t gclient_t, *Pgclient_t;

typedef struct client_persistant_t client_persistant_t, *Pclient_persistant_t;

struct gentity_t {
    struct entityState_t s;
    struct gclient_t * client;
    int inuse;
    int linked;
    int linkcount;
    int svFlags;
    int bmodel;
    float mins[3];
    float maxs[3];
    int contents;
    float absmins[3];
    float absmaxs[3];
    float radius;
    float centroid[3];
    int areanum;
    float currentOrigin[3];
    float currentAngles[3];
    int ownerNum;
    int solid;
    pointer Entity;
    float freetime;
    float spawntime;
    float radius2;
    char netname[64];
    int clipmask;
    struct gentity_t * next;
    struct gentity_t * prev;
};

struct client_persistant_t {
    char userinfo[1024];
    char netname[16];
    int health;
    int max_health;
};

struct cplane_t {
    float endpos[3];
    float normal[3];
    float dist;
    byte type;
    byte signbits;
    byte pad[2];
};

struct trace_t {
    int allsolid;
    int startsolid;
    float fraction;
    struct cplane_t plane;
    int surfaceFlags;
    int contents;
    int entityNum;
    struct gentity_t * ent;
};

struct playerState_t {
    int commandTime;
    int pm_type;
    int bobcycle;
    int pm_flags;
    int pm_time;
    int pm_runtime;
    float origin[3];
    float velocity[3];
    int gravity;
    int speed;
    int delta_angles[3];
    int groundEntityNum;
    int walking;
    int groundPlane;
    int feetfalling;
    float falldir[3];
    struct trace_t groundTrace;
    int clientNum;
    float viewangles[3];
    int viewheight; /* Created by retype action */
    int stats[32];
    int activeItems[32];
    int inventory_name_index[32];
    int ammo_name_index[32];
    int ammo_amount[32];
    int max_ammo_amount[32];
    int current_music_mood;
    int fallback_music_mood;
    float music_volume;
    float music_volume_fade_time;
    int reverb_type;
    float reverb_level;
    float blend[4];
    float fov;
    float camera_origin[3];
    float camera_angles[3];
    float camera_time;
    float camera_offset[3];
    float damage_angles[3];
    int camera_flags;
    int ping;
};

struct server_sound_t {
    float origin[3];
    int entity_number;
    int channel;
    short sound_index;
    float volume;
    float min_dist;
    int stop_flag;
};

struct snapshot_t {
    int snapFlags;
    int ping;
    int serverTime;
    byte areamask[32];
    struct playerState_t ps;
    int num_entities;
    struct entityState_t entities[256];
    int numServerCommands;
    int serverCommandSequence;
    int number_of_sounds;
    struct server_sound_t sounds[32];
};

struct refEntity_t {
    int reType;
    int renderfx;
    uint rendereflags;
    int hModel;
    float lightingOrigin[3];
    float shadowPlane;
    float axis[3][3];
    int nonNormalizedAxes;
    float origin[3];
    int anim;
    int oldanim;
    short oldframe;
    short frame;
    float scale;
    int useAngles;
    int torso_anim;
    int torso_oldanim;
    short torso_frame;
    short torso_oldframe;
    float crossblend_lerp;
    float crossblend_backlerp;
    int crossblend_anim;
    short crossblend_frame;
    short crossblend_oldframe;
    int uselegs;
    float torso_crossblend_lerp;
    float torso_crossblend_backlerp;
    int torso_crossblend_anim;
    short torso_crossblend_frame;
    short torso_crossblend_oldframe;
    int usetorso;
    float oldorigin[3];
    float backlerp;
    float torso_backlerp;
    int skinNum;
    int customSkin;
    int customShader;
    byte shaderRGBA[4];
    float shaderTexCoord[2][2];
    float shaderTime;
    int entityNumber;
    byte surfaces[32];
    short shader_data[2];
    struct bone_controller_t bone_controllers[5];
    pointer of;
    pointer nf;
    pointer tiki;
    int bonestart;
    float radius;
    float rotation;
    int unk0;
    int unk1;
    int unk2;
};

struct refdef_t {
    int x;
    int y;
    int width;
    int height;
    float fov_x;
    float fov_y;
    float vieworg[3];
    float viewaxis[3][3];
    int time;
    int rdflags;
    byte areamask[32];
    char text[8][32];
    float farplane_distance;
    float farplane_color[3];
    int farplane_cull;
    int sky_portal;
    float sky_alpha;
    float sky_origin[3];
    float sky_axis[3][3];
};

struct cg_t {
    int clientFrame;
    int demoPlayback;
    int levelShot;
    int latestSnapshotNum;
    int latestSnapshotTime;
    struct snapshot_t * snap;
    struct snapshot_t * nextSnap;
    struct snapshot_t activeSnapshots[2];
    float frameInterpolation; /* Created by retype action */
    int thisFrameTeleport;
    int nextFrameTeleport;
    int nextFrameCameraCut;
    int frametime;
    int time;
    int oldTime;
    int physicsTime;
    int timelimitWarnings;
    int unknown;
    int renderingThirdPerson;
    int hyperspace;
    struct playerState_t predicted_player_state;
    int validPPS;
    int predictedErrorTime;
    float predictedError[3];
    float stepChange;
    int stepTime;
    float duckChange;
    int duckTime;
    float landChange;
    int landTime;
    int weaponselect;
    float autoAngles[3];
    float autoAxis[3][3];
    float autoAnglesSlow[3];
    float autoAxisSlow[3][3];
    float autoAnglesFast[3];
    float autoAxisFast[3][3];
    struct refdef_t refdef;
    int unknown1;
    float playerHeadPos[3];
    float refdefViewAngles[3];
    float currentViewPos[3];
    float currentViewAngles[3];
    float SoundOrg[3];
    float SoundAxis[3][3];
    int lastCameraTime;
    float lerpCameraTime;
    int inCameraView; /* Created by retype action */
    float camera_origin[3];
    float camera_angles[3];
    float camera_fov; /* Created by retype action */
    int lastCmaerFlags;
    int zoomed;
    int zoomTime;
    float zoomSensitivity;
    char infoScreenText[1024];
    int showInformation;
    int scoresRequestTime;
    int numScores;
    int teamScores[2];
    int showScores;
    int scoreFadeTime;
    char killerName[32];
    int centerPrintTime;
    int centerPrintCharWidth;
    int centerPrintY;
    char centerPrint[1024];
    int centerPrintLines;
    int lowAmmoWarning;
    int lastKillTime;
    int crosshairClientNum;
    int crosshairClientTime;
    float crosshair_offset;
    int powerupActive;
    int powerupTime;
    int attackerTime;
    int warmupCount;
    int itemPickup;
    int itemPickupTime;
    int itemPickupBlendTime;
    int weaponSelectTime;
    int weaponAnimation;
    int weaponAnimationTime;
    float damageTime;
    float damageX;
    float damageY;
    float damageValue;
    float headYaw;
    float headEndPitch;
    float headEntYaw;
    int headEntTime;
    float headStartPitch;
    float headStartYaw;
    int headStartTime;
    float v_dmg_time;
    float v_dmg_pitch;
    float v_dmg_roll;
    float kick_angles[3];
    float kick_origin[3];
    float bobcyclesin;
    int bobcycle; /* Created by retype action */
    float xyspeed;
    struct refEntity_t testModelEntity;
    char testModelName[64];
    int testGun;
    float farplane_distance;
    float farplane_color[3];
    int farplane_cull;
    int unknown2;
    int unknown3;
    int sky_portal;
    float sky_alpha;
    float sky_origin[3];
    float sky_axis[3][3];
    int unknown4;
    int unknown5;
    int unknown6;
    int unknown7;
    int unknown8;
    int unknown9;
    int unknown10;
    int unknown11;
    int unknown12;
    int unknown13;
    int unknown14;
    int unknown15;
    int unknown16;
};

struct gclient_t {
    struct playerState_t ps;
    int ping;
    struct client_persistant_t pers;
    float cmd_angles[3];
};

typedef struct cgs_t cgs_t, *Pcgs_t;

typedef struct gameState_t gameState_t, *PgameState_t;

typedef struct glconfig_t glconfig_t, *Pglconfig_t;

typedef struct media_t media_t, *Pmedia_t;

struct gameState_t {
    int stringOffsets[1328];
    char stringData[16000];
    int dataCount;
};

struct glconfig_t {
    char renderer_string[1024];
    char vendor_string[1024];
    char version_string[1024];
    char extensions_string[4096];
    int maxTextureSize;
    int maxActiveTextures;
    int colorBits;
    int depthBits;
    int stencilBits;
    int driverType;
    int hardwareType;
    int deviceSupportsGamma;
    int textureCompression;
    int textureEnvAddAvailable;
    int vidWidth;
    int vidHeight;
    float windowAspect;
    int displayFrequency;
    int isFullscreen;
    int stereoEnabled;
    int smpActive;
};

struct media_t {
    int backTileShader;
    int shadowMarkShader;
    int wakeMarkShader;
    int targetShader;
    int leftTargetModel;
    int rightTargetModel;
    int pentagramShader;
    int pausedShader;
};

struct cgs_t {
    struct gameState_t gameState;
    struct glconfig_t glconfig;
    float screenXScale;
    float screenYScale; /* Created by retype action */
    float screenYBias;
    int serverCommandSequence;
    int processedSnapshotNum;
    int localServer;
    int levelStartTime;
    int gametype;
    int dmflags;
    int teamflags;
    int fraglimit;
    int timelimit;
    int maxclients;
    int cinematic;
    char mapname[64];
    int model_draw[512];
    int sound_precache[256];
    int numInlineModels;
    int inlineDrawModel[512];
    float inlineModelMidPoints[3][512];
    int model_tiki[512];
    byte unk[38912];
    struct media_t media;
};

typedef struct clientInfo_t clientInfo_t, *PclientInfo_t;

struct clientInfo_t {
    char name[64];
    char data[64];
    int legsModel;
    int legsSkin;
    int torsoModel;
    int torsoSkin;
    int headModel;
    int headSkin;
    pointer sounds[32];
    float color[3];
    float color2[3];
};

typedef struct Game Game, *PGame;

struct Game {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    struct gclient_t * clients;
    int autosaved;
    int maxclients;
    int maxentities;
};

typedef struct polyVert_t polyVert_t, *PpolyVert_t;

struct polyVert_t { /* PlaceHolder Structure */
    float xyz[3];
    float st[2];
    byte modulate[4];
};

typedef struct scriptmarker_t scriptmarker_t, *Pscriptmarker_t;

struct scriptmarker_t { /* PlaceHolder Structure */
    bool tokenready;
    int offset;
    int line;
    char token[256];
};

#define TIKI_CMD_MAX_ARGS 10

#define TIKI_CMD_MAX_CMDS 128

typedef struct consolecmd_t consolecmd_t, *Pconsolecmd_t;

struct consolecmd_t {
    char * command; /* command name */
    void * func; /* function */
    int allclients; /* available in multiplayer? */
};

typedef struct clientGameExport_t clientGameExport_t, *PclientGameExport_t;

struct clientGameExport_t {
    void * CG_Init;
    void * CG_Shutdown;
    void * CG_DrawActiveFrame;
    void * CG_ConsoleCommand;
    void * CG_GetRendererConfig;
    void * CG_Draw2D;
    void * CG_GetInterpState;
};

typedef struct clientGameImport_t clientGameImport_t, *PclientGameImport_t;

typedef struct cvar_t cvar_t, *Pcvar_t;

typedef int clipHandle_t;

typedef struct markFragment_t markFragment_t, *PmarkFragment_t;

typedef struct shared_handle_t shared_handle_t, *Pshared_handle_t;

struct clientGameImport_t {
    int apiversion;
    void (* Printf)(char *, ...);
    void (* DPrintf)(char *, ...);
    void (* DebugPrintf)(char *, ...);
    void * (* Malloc)(int);
    void (* Free)(void *);
    void (* Error)(int, char *, ...);
    int (* Milliseconds)(void);
    cvar_t * (* Cvar_Get)(char *, char *, int);
    void (* Cvar_Set)(char *, char *);
    int (* Argc)(void);
    char * (* Argv)(int);
    char * (* Args)(void);
    void (* AddCommand)(char *);
    int (* FS_ReadFile)(char *, void * *, int);
    void (* FS_FreeFile)(void *);
    void (* FS_WriteFile)(char *, void *, int);
    void (* FS_WriteTextFile)(char *, void *, int);
    void (* SendConsoleCommand)(char *);
    void (* UpdateLoadingScreen)(void);
    void (* SendClientCommand)(char *);
    void (* CM_LoadMap)(char *);
    clipHandle_t (* CM_InlineModel)(int);
    int (* CM_NumInlineModels)(void);
    undefined * CM_PointContents;
    undefined * CM_TransformedPointContents;
    void (* CM_BoxTrace)(struct trace_t *, float *, float *, float *, float *, int, int, int);
    undefined * CM_TransformedBoxTrace;
    undefined * CM_TempBoxModel;
    int (* CM_MarkFragments)(int, float *, float *, int, float *, int, struct markFragment_t *);
    undefined * S_StartSound;
    undefined * S_StartLocalSound;
    undefined * S_StopSound;
    undefined * S_ClearLoopingSounds;
    undefined * S_AddLoopingSounds;
    undefined * S_Respatialize;
    undefined * S_BeginRegistration;
    undefined * S_RegisterSound;
    undefined * S_EndRegisteration;
    undefined * S_UpdateEntity;
    undefined * S_SetReverb;
    undefined * S_SetGlobalAmbientVolumeLevel;
    undefined * MUSIC_NewSoundtrack;
    undefined * MUSIC_UpdateMood;
    undefined * MUSIC_UpdateVolume;
    undefined * get_lip_length;
    undefined * get_lip_amplitudes;
    undefined * get_camera_offset;
    undefined * BeginRegistration;
    undefined4 EndRegistration;
    undefined4 R_ClearScene;
    undefined4 R_RenderScene;
    undefined4 R_LoadWorldMap;
    undefined4 R_RegisterModel;
    undefined4 R_RegisterSkin;
    undefined4 R_RegisterShader;
    undefined4 R_RegisterShaderNoMip;
    undefined4 R_AddRefEntityToScene;
    undefined4 R_AddRefSpriteToScene;
    undefined4 R_AddLightToScene;
    undefined4 R_AddPolyToScene;
    undefined4 R_SetColor;
    undefined4 R_DrawStretchPic;
    undefined4 R_GetRenderEntity;
    undefined4 R_ModelBounds;
    undefined4 R_ModelRadius;
    undefined4 R_Noise;
    undefined4 R_DebugLine;
    undefined4 R_SwipeBegin;
    undefined4 R_SwipePoint;
    undefined4 R_SwipeEnd;
    undefined4 R_GetShaderWidth;
    undefined4 R_GetShaderHeight;
    undefined4 R_DrawBox;
    undefined * GetGameState;
    undefined * GetSnapshot;
    undefined * GetCurrentSnapshotNumber;
    undefined * GetGlconfig;
    undefined * GetParseEntityState;
    undefined * GetCurrentCmdNumber;
    undefined * GetUserCmd;
    undefined * GetServerCommand;
    undefined * Alias_Add;
    undefined * Alias_FindRandom;
    undefined * Alias_Dump;
    undefined * Alias_Clear;
    undefined4 TIKI_GetHandle;
    undefined * NumAnims;
    undefined * NumSkins;
    undefined * NumSurfaces;
    undefined * NumTags;
    undefined * InitCommands;
    undefined * CalculateBounds;
    undefined4 FlushAll;
    undefined * TIKI_NameForNum;
    undefined * Anim_NameForNum;
    undefined * Anim_NumForName;
    undefined * Anim_Random;
    undefined * Anim_NumFrames;
    undefined * Anim_Time;
    undefined * Anim_Delta;
    undefined * Anim_Flags;
    undefined * Anim_CrossblendTime;
    undefined * Anim_HasCommands;
    undefined * Frame_Commands;
    undefined * Frame_Delta;
    undefined * Frame_Time;
    undefined * Frame_Bounds;
    undefined * Frame_Radius;
    undefined * Surface_NameToNum;
    undefined * Surface_NumToName;
    undefined * Surface_Flags;
    undefined * Surface_NumSkins;
    undefined * Tag_NumForName;
    undefined * Tag_NameForNum;
    undefined * Tag_Orientation;
    undefined * Tag_OrientationEx;
    undefined * Tag_NamedOrietation;
    undefined * Tag_LerpedOrientation;
    undefined * TIKI_Alias_Add;
    undefined * TIKI_Alias_FindRandom;
    undefined * TIKI_Alias_Dump;
    undefined * TIKI_Alias_Clear;
    undefined * TIKI_Alias_FindDialog;
    shared_handle_t * (* CL_GetSharedHandle)(void);
};

struct cvar_t {
    char * name;
    char * string;
    char * resetString;
    char * latchedString;
    int flags;
    int modified;
    int modificationCount;
    float value;
    int integer;
    void * next;
};

struct shared_handle_t {
    float vieworg[3];
    float viewangles[3];
    pointer G_Trace;
    pointer CG_Trace;
    float unk0;
    float unk1;
    int unk_bool0;
    int unk_bool1;
    int unk_bool2;
    int unk_bool3;
    int unk2;
};

struct markFragment_t {
    int firstPoint;
    int numPoints;
};

typedef struct debugline_t debugline_t, *Pdebugline_t;

struct debugline_t {
    float start[3];
    float end[3];
    float color[3];
    float alpha;
    float width;
    ushort factor;
    ushort pattern;
};

typedef struct game_export_t game_export_t, *Pgame_export_t;

struct game_export_t {
    int apiversion;
    void * Init;
    void * Shutdown;
    void * Cleanup;
    void * SpawnEntities;
    void * ClientConnect;
    void * ClientBegin;
    void * ClientUserinfoChanged;
    void * ClientDisconnect;
    void * ClientCommand;
    void * ClientThink;
    void * BotBegin;
    void * BotThink;
    void * PrepFrame;
    void * RunFrame;
    void * ConsoleCommand;
    void * WritePersistant;
    void * ReadPersistant;
    void * WriteLevel;
    void * ReadLevel;
    void * LevelArchiveValid;
    struct gentity_t * gentities;
    int gentitySize;
    int num_entities;
    int max_entities;
    char * error_message;
};

typedef struct game_import_t game_import_t, *Pgame_import_t;

struct game_import_t {
    void (* Printf)(char *, ...);
    void (* DPrintf)(char *, ...);
    void (* DebugPrintf)(char *, ...);
    void (* Error)(int, char *, ...);
    int (* Milliseconds)(void);
    void * (* Malloc)(int);
    void (* Free)(void *);
    void (* Cvar_Set)(char *, char *);
    cvar_t * (* Cvar_Get)(char *, char *, int);
    int (* Cmd_Argc)(void);
    char * (* Cmd_Argv)(int);
    char * (* Cmd_Args)(void);
    void (* AddCommand)(char *);
    int (* FS_ReadFile)(char *, void * *, int);
    void (* FS_FreeFile)(void *);
    void (* FS_WriteFile)(char *, void *, int);
    void * FS_FOpenFileWrite;
    void * FS_FopenFileAppend;
    void * FS_PrepFileWrite;
    void * FS_Write;
    void * FS_Read;
    void * FS_FCloseFile;
    void * FS_FTell;
    void * FS_FSeek;
    void * FS_Flush;
    void * GetArchiveFileName;
    void * SendConsoleCommand;
    void * DebugGraph;
    void * SendServerCommand;
    void * setConfigstring;
    void * getConfigstring;
    void * setUserinfo;
    void * getUserinfo;
    void * SetBrushModel;
    void * trace;
    void * pointcontents;
    void * pointbrushnum;
    void * inPVS;
    void * inPVSIgnorePortals;
    void * AdjustAreaPortalState;
    void * AreasConnected;
    void * linkentity;
    void * unlinkentity;
    void * AreaEntities;
    void * ClipToEntity;
    void * imageindex;
    void * itemindex;
    void * soundindex;
    void * modelindex;
    void * SetLightStyle;
    void * GameDir;
    void * IsModel;
    void * setmodel;
    pointer NumAnims;
    pointer NumSkins;
    pointer NumSurfaces;
    pointer NumTags;
    pointer InitCommands;
    pointer CalculateBounds;
    pointer Anim_NameForNum;
    pointer Anim_NumForName;
    pointer Anim_Random;
    pointer Anim_NumFrames;
    pointer Anim_Time;
    pointer Anim_Delta;
    pointer Anim_AbsoluteDelta;
    pointer Anim_Flags;
    pointer Anim_HasCommands;
    pointer Frame_Commands;
    pointer Frame_Delta;
    pointer Frame_Time;
    pointer Frame_Bounds;
    pointer Surface_NameToNum;
    pointer Surface_NumToName;
    pointer Surface_Flags;
    pointer Surface_NumSkins;
    pointer Tag_NumForName;
    pointer Tag_NameForNum;
    pointer Tag_Orientation;
    pointer Tag_OrientationEx;
    pointer Alias_Add;
    pointer Alias_FindRandom;
    pointer Alias_Dump;
    pointer Alias_Clear;
    pointer Alias_FindDialog;
    pointer Alias_GetList;
    pointer Alias_UpdateDialog;
    pointer Alias_AddActorDialog;
    pointer NameForNum;
    pointer GlobalAlias_Add;
    pointer GlobalAlias_FindRandom;
    pointer GlobalAlias_Dump;
    pointer GlobalAlias_Clear;
    pointer centerprintf;
    pointer locationprintf;
    pointer Sound;
    pointer StopSound;
    pointer SoundLength;
    pointer SoundAmplitudes;
    pointer CalcCRC;
    pointer unknown;
    struct debugline_t * DebugLines;
    int numDebugLines;
    pointer LocateGameData;
    pointer SetFarPlane;
    pointer SetSkyPortal;
    pointer Com_WidgetPrintf;
    shared_handle_t * (* CL_GetSharedHandle)(void);
    pointer UI_SetLoadingStage;
    pointer CL_UpdateLoadingScreen;
    pointer Cbuf_ExecuteText;
};

typedef struct tiki_cmd_t tiki_cmd_t, *Ptiki_cmd_t;

typedef struct tiki_singlecmd_t tiki_singlecmd_t, *Ptiki_singlecmd_t;

struct tiki_singlecmd_t {
    int num_args;
    char * args[13];
};

struct tiki_cmd_t {
    int num_cmds;
    struct tiki_singlecmd_t cmds[128];
};

