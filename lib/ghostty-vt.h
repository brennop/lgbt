typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef long unsigned int rsize_t;
typedef int wchar_t;
typedef long double max_align_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;
typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;
typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;
typedef __mbstate_t __darwin_mbstate_t;
typedef long int __darwin_ptrdiff_t;
typedef long unsigned int __darwin_size_t;
typedef __builtin_va_list __darwin_va_list;
typedef int __darwin_wchar_t;
typedef __darwin_wchar_t __darwin_rune_t;
typedef int __darwin_wint_t;
typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;
typedef __darwin_ino64_t __darwin_ino_t;
typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];
struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};
struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};
struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};
struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};
struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};
struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};
struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};
struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};
struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};
struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};
typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;
typedef enum {
    GHOSTTY_SUCCESS = 0,
    GHOSTTY_OUT_OF_MEMORY = -1,
    GHOSTTY_INVALID_VALUE = -2,
    GHOSTTY_OUT_OF_SPACE = -3,
    GHOSTTY_NO_VALUE = -4,
    GHOSTTY_RESULT_MAX_VALUE = 2147483647,
} GhosttyResult;
typedef struct GhosttyTerminalImpl* GhosttyTerminal;
typedef struct GhosttyTrackedGridRefImpl* GhosttyTrackedGridRef;
typedef struct GhosttyKittyGraphicsImpl* GhosttyKittyGraphics;
typedef const struct GhosttyKittyGraphicsImageImpl* GhosttyKittyGraphicsImage;
typedef struct GhosttyKittyGraphicsPlacementIteratorImpl* GhosttyKittyGraphicsPlacementIterator;
typedef struct GhosttyRenderStateImpl* GhosttyRenderState;
typedef struct GhosttyRenderStateRowIteratorImpl* GhosttyRenderStateRowIterator;
typedef struct GhosttyRenderStateRowCellsImpl* GhosttyRenderStateRowCells;
typedef struct GhosttySgrParserImpl* GhosttySgrParser;
typedef struct GhosttyFormatterImpl* GhosttyFormatter;
typedef struct GhosttyOscParserImpl* GhosttyOscParser;
typedef struct GhosttyOscCommandImpl* GhosttyOscCommand;
typedef enum {
  GHOSTTY_FORMATTER_FORMAT_PLAIN,
  GHOSTTY_FORMATTER_FORMAT_VT,
  GHOSTTY_FORMATTER_FORMAT_HTML,
  GHOSTTY_FORMATTER_FORMAT_MAX_VALUE = 2147483647,
} GhosttyFormatterFormat;
typedef struct {
  const uint8_t* ptr;
  size_t len;
} GhosttyString;
typedef struct {
  uint8_t* ptr;
  size_t cap;
  size_t len;
} GhosttyBuffer;
typedef struct {
  double x;
  double y;
} GhosttySurfacePosition;
typedef struct {
  const uint32_t* ptr;
  size_t len;
} GhosttyCodepoints;
__attribute__((visibility("default"))) const char *ghostty_type_json(void);
typedef struct {
    void* (*alloc)(void *ctx, size_t len, uint8_t alignment, uintptr_t ret_addr);
    uint8_t (*resize)(void *ctx, void *memory, size_t memory_len, uint8_t alignment, size_t new_len, uintptr_t ret_addr);
    void* (*remap)(void *ctx, void *memory, size_t memory_len, uint8_t alignment, size_t new_len, uintptr_t ret_addr);
    void (*free)(void *ctx, void *memory, size_t memory_len, uint8_t alignment, uintptr_t ret_addr);
} GhosttyAllocatorVtable;
typedef struct GhosttyAllocator {
    void *ctx;
    const GhosttyAllocatorVtable *vtable;
} GhosttyAllocator;
__attribute__((visibility("default"))) uint8_t* ghostty_alloc(const GhosttyAllocator* allocator, size_t len);
__attribute__((visibility("default"))) void ghostty_free(const GhosttyAllocator* allocator, uint8_t* ptr, size_t len);
typedef enum {
  GHOSTTY_OPTIMIZE_DEBUG = 0,
  GHOSTTY_OPTIMIZE_RELEASE_SAFE = 1,
  GHOSTTY_OPTIMIZE_RELEASE_SMALL = 2,
  GHOSTTY_OPTIMIZE_RELEASE_FAST = 3,
  GHOSTTY_OPTIMIZE_MODE_MAX_VALUE = 2147483647,
} GhosttyOptimizeMode;
typedef enum {
  GHOSTTY_BUILD_INFO_INVALID = 0,
  GHOSTTY_BUILD_INFO_SIMD = 1,
  GHOSTTY_BUILD_INFO_KITTY_GRAPHICS = 2,
  GHOSTTY_BUILD_INFO_TMUX_CONTROL_MODE = 3,
  GHOSTTY_BUILD_INFO_OPTIMIZE = 4,
  GHOSTTY_BUILD_INFO_VERSION_STRING = 5,
  GHOSTTY_BUILD_INFO_VERSION_MAJOR = 6,
  GHOSTTY_BUILD_INFO_VERSION_MINOR = 7,
  GHOSTTY_BUILD_INFO_VERSION_PATCH = 8,
  GHOSTTY_BUILD_INFO_VERSION_PRE = 9,
  GHOSTTY_BUILD_INFO_VERSION_BUILD = 10,
  GHOSTTY_BUILD_INFO_MAX_VALUE = 2147483647,
} GhosttyBuildInfo;
__attribute__((visibility("default"))) GhosttyResult ghostty_build_info(GhosttyBuildInfo data, void *out);
typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} GhosttyColorRgb;
typedef uint8_t GhosttyColorPaletteIndex;
__attribute__((visibility("default"))) void ghostty_color_rgb_get(GhosttyColorRgb color,
                           uint8_t* r,
                           uint8_t* g,
                           uint8_t* b);
typedef enum {
    GHOSTTY_COLOR_SCHEME_LIGHT = 0,
    GHOSTTY_COLOR_SCHEME_DARK = 1,
    GHOSTTY_COLOR_SCHEME_MAX_VALUE = 2147483647,
} GhosttyColorScheme;
typedef struct {
    uint16_t conformance_level;
    uint16_t features[64];
    size_t num_features;
} GhosttyDeviceAttributesPrimary;
typedef struct {
    uint16_t device_type;
    uint16_t firmware_version;
    uint16_t rom_cartridge;
} GhosttyDeviceAttributesSecondary;
typedef struct {
    uint32_t unit_id;
} GhosttyDeviceAttributesTertiary;
typedef struct {
    GhosttyDeviceAttributesPrimary primary;
    GhosttyDeviceAttributesSecondary secondary;
    GhosttyDeviceAttributesTertiary tertiary;
} GhosttyDeviceAttributes;
typedef enum {
    GHOSTTY_FOCUS_GAINED = 0,
    GHOSTTY_FOCUS_LOST = 1,
    GHOSTTY_FOCUS_MAX_VALUE = 2147483647,
} GhosttyFocusEvent;
__attribute__((visibility("default"))) GhosttyResult ghostty_focus_encode(
    GhosttyFocusEvent event,
    char* buf,
    size_t buf_len,
    size_t* out_written);
typedef uint64_t GhosttyCell;
typedef uint64_t GhosttyRow;
typedef enum {
  GHOSTTY_CELL_CONTENT_CODEPOINT = 0,
  GHOSTTY_CELL_CONTENT_CODEPOINT_GRAPHEME = 1,
  GHOSTTY_CELL_CONTENT_BG_COLOR_PALETTE = 2,
  GHOSTTY_CELL_CONTENT_BG_COLOR_RGB = 3,
  GHOSTTY_CELL_CONTENT_TAG_MAX_VALUE = 2147483647,
} GhosttyCellContentTag;
typedef enum {
  GHOSTTY_CELL_WIDE_NARROW = 0,
  GHOSTTY_CELL_WIDE_WIDE = 1,
  GHOSTTY_CELL_WIDE_SPACER_TAIL = 2,
  GHOSTTY_CELL_WIDE_SPACER_HEAD = 3,
  GHOSTTY_CELL_WIDE_MAX_VALUE = 2147483647,
} GhosttyCellWide;
typedef enum {
  GHOSTTY_CELL_SEMANTIC_OUTPUT = 0,
  GHOSTTY_CELL_SEMANTIC_INPUT = 1,
  GHOSTTY_CELL_SEMANTIC_PROMPT = 2,
  GHOSTTY_CELL_SEMANTIC_MAX_VALUE = 2147483647,
} GhosttyCellSemanticContent;
typedef enum {
  GHOSTTY_CELL_DATA_INVALID = 0,
  GHOSTTY_CELL_DATA_CODEPOINT = 1,
  GHOSTTY_CELL_DATA_CONTENT_TAG = 2,
  GHOSTTY_CELL_DATA_WIDE = 3,
  GHOSTTY_CELL_DATA_HAS_TEXT = 4,
  GHOSTTY_CELL_DATA_HAS_STYLING = 5,
  GHOSTTY_CELL_DATA_STYLE_ID = 6,
  GHOSTTY_CELL_DATA_HAS_HYPERLINK = 7,
  GHOSTTY_CELL_DATA_PROTECTED = 8,
  GHOSTTY_CELL_DATA_SEMANTIC_CONTENT = 9,
  GHOSTTY_CELL_DATA_COLOR_PALETTE = 10,
  GHOSTTY_CELL_DATA_COLOR_RGB = 11,
  GHOSTTY_CELL_DATA_MAX_VALUE = 2147483647,
} GhosttyCellData;
typedef enum {
  GHOSTTY_ROW_SEMANTIC_NONE = 0,
  GHOSTTY_ROW_SEMANTIC_PROMPT = 1,
  GHOSTTY_ROW_SEMANTIC_PROMPT_CONTINUATION = 2,
  GHOSTTY_ROW_SEMANTIC_MAX_VALUE = 2147483647,
} GhosttyRowSemanticPrompt;
typedef enum {
  GHOSTTY_ROW_DATA_INVALID = 0,
  GHOSTTY_ROW_DATA_WRAP = 1,
  GHOSTTY_ROW_DATA_WRAP_CONTINUATION = 2,
  GHOSTTY_ROW_DATA_GRAPHEME = 3,
  GHOSTTY_ROW_DATA_STYLED = 4,
  GHOSTTY_ROW_DATA_HYPERLINK = 5,
  GHOSTTY_ROW_DATA_SEMANTIC_PROMPT = 6,
  GHOSTTY_ROW_DATA_KITTY_VIRTUAL_PLACEHOLDER = 7,
  GHOSTTY_ROW_DATA_DIRTY = 8,
  GHOSTTY_ROW_DATA_MAX_VALUE = 2147483647,
} GhosttyRowData;
__attribute__((visibility("default"))) GhosttyResult ghostty_cell_get(GhosttyCell cell,
                                GhosttyCellData data,
                                void *out);
__attribute__((visibility("default"))) GhosttyResult ghostty_cell_get_multi(GhosttyCell cell,
                                     size_t count,
                                     const GhosttyCellData* keys,
                                     void** values,
                                     size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_row_get(GhosttyRow row,
                               GhosttyRowData data,
                               void *out);
__attribute__((visibility("default"))) GhosttyResult ghostty_row_get_multi(GhosttyRow row,
                                    size_t count,
                                    const GhosttyRowData* keys,
                                    void** values,
                                    size_t* out_written);
typedef uint16_t GhosttyStyleId;
typedef enum {
  GHOSTTY_STYLE_COLOR_NONE = 0,
  GHOSTTY_STYLE_COLOR_PALETTE = 1,
  GHOSTTY_STYLE_COLOR_RGB = 2,
  GHOSTTY_STYLE_COLOR_TAG_MAX_VALUE = 2147483647,
  } GhosttyStyleColorTag;
typedef union {
  GhosttyColorPaletteIndex palette;
  GhosttyColorRgb rgb;
  uint64_t _padding;
} GhosttyStyleColorValue;
typedef struct {
  GhosttyStyleColorTag tag;
  GhosttyStyleColorValue value;
} GhosttyStyleColor;
typedef struct {
  size_t size;
  GhosttyStyleColor fg_color;
  GhosttyStyleColor bg_color;
  GhosttyStyleColor underline_color;
  uint8_t bold;
  uint8_t italic;
  uint8_t faint;
  uint8_t blink;
  uint8_t inverse;
  uint8_t invisible;
  uint8_t strikethrough;
  uint8_t overline;
  int underline;
} GhosttyStyle;
__attribute__((visibility("default"))) void ghostty_style_default(GhosttyStyle* style);
__attribute__((visibility("default"))) uint8_t ghostty_style_is_default(const GhosttyStyle* style);
typedef struct {
  size_t size;
  void *node;
  uint16_t x;
  uint16_t y;
} GhosttyGridRef;
__attribute__((visibility("default"))) GhosttyResult ghostty_grid_ref_cell(const GhosttyGridRef *ref,
                                    GhosttyCell *out_cell);
__attribute__((visibility("default"))) GhosttyResult ghostty_grid_ref_row(const GhosttyGridRef *ref,
                                   GhosttyRow *out_row);
__attribute__((visibility("default"))) GhosttyResult ghostty_grid_ref_graphemes(const GhosttyGridRef *ref,
                                         uint32_t *buf,
                                         size_t buf_len,
                                         size_t *out_len);
__attribute__((visibility("default"))) GhosttyResult ghostty_grid_ref_hyperlink_uri(
    const GhosttyGridRef *ref,
    uint8_t *buf,
    size_t buf_len,
    size_t *out_len);
__attribute__((visibility("default"))) GhosttyResult ghostty_grid_ref_style(const GhosttyGridRef *ref,
                                     GhosttyStyle *out_style);
typedef struct {
  uint16_t x;
  uint32_t y;
} GhosttyPointCoordinate;
typedef enum {
  GHOSTTY_POINT_TAG_ACTIVE = 0,
  GHOSTTY_POINT_TAG_VIEWPORT = 1,
  GHOSTTY_POINT_TAG_SCREEN = 2,
  GHOSTTY_POINT_TAG_HISTORY = 3,
  GHOSTTY_POINT_TAG_MAX_VALUE = 2147483647,
  } GhosttyPointTag;
typedef union {
  GhosttyPointCoordinate coordinate;
  uint64_t _padding[2];
} GhosttyPointValue;
typedef struct {
  GhosttyPointTag tag;
  GhosttyPointValue value;
} GhosttyPoint;
typedef struct GhosttySelectionGestureImpl* GhosttySelectionGesture;
typedef struct GhosttySelectionGestureEventImpl* GhosttySelectionGestureEvent;
typedef struct {
  size_t size;
  GhosttyGridRef start;
  GhosttyGridRef end;
  uint8_t rectangle;
} GhosttySelection;
typedef struct {
  size_t size;
  GhosttyGridRef ref;
  const uint32_t* boundary_codepoints;
  size_t boundary_codepoints_len;
} GhosttyTerminalSelectWordOptions;
typedef struct {
  size_t size;
  GhosttyGridRef start;
  GhosttyGridRef end;
  const uint32_t* boundary_codepoints;
  size_t boundary_codepoints_len;
} GhosttyTerminalSelectWordBetweenOptions;
typedef struct {
  size_t size;
  GhosttyGridRef ref;
  const uint32_t* whitespace;
  size_t whitespace_len;
  uint8_t semantic_prompt_boundary;
} GhosttyTerminalSelectLineOptions;
typedef struct {
  size_t size;
  GhosttyFormatterFormat emit;
  uint8_t unwrap;
  uint8_t trim;
  const GhosttySelection *selection;
} GhosttyTerminalSelectionFormatOptions;
typedef enum {
  GHOSTTY_SELECTION_ORDER_FORWARD = 0,
  GHOSTTY_SELECTION_ORDER_REVERSE = 1,
  GHOSTTY_SELECTION_ORDER_MIRRORED_FORWARD = 2,
  GHOSTTY_SELECTION_ORDER_MIRRORED_REVERSE = 3,
  GHOSTTY_SELECTION_ORDER_MAX_VALUE = 2147483647,
} GhosttySelectionOrder;
typedef enum {
  GHOSTTY_SELECTION_ADJUST_LEFT = 0,
  GHOSTTY_SELECTION_ADJUST_RIGHT = 1,
  GHOSTTY_SELECTION_ADJUST_UP = 2,
  GHOSTTY_SELECTION_ADJUST_DOWN = 3,
  GHOSTTY_SELECTION_ADJUST_HOME = 4,
  GHOSTTY_SELECTION_ADJUST_END = 5,
  GHOSTTY_SELECTION_ADJUST_PAGE_UP = 6,
  GHOSTTY_SELECTION_ADJUST_PAGE_DOWN = 7,
  GHOSTTY_SELECTION_ADJUST_BEGINNING_OF_LINE = 8,
  GHOSTTY_SELECTION_ADJUST_END_OF_LINE = 9,
  GHOSTTY_SELECTION_ADJUST_MAX_VALUE = 2147483647,
} GhosttySelectionAdjust;
typedef enum {
  GHOSTTY_SELECTION_GESTURE_BEHAVIOR_CELL = 0,
  GHOSTTY_SELECTION_GESTURE_BEHAVIOR_WORD = 1,
  GHOSTTY_SELECTION_GESTURE_BEHAVIOR_LINE = 2,
  GHOSTTY_SELECTION_GESTURE_BEHAVIOR_OUTPUT = 3,
  GHOSTTY_SELECTION_GESTURE_BEHAVIOR_MAX_VALUE = 2147483647,
} GhosttySelectionGestureBehavior;
typedef struct {
  GhosttySelectionGestureBehavior single_click;
  GhosttySelectionGestureBehavior double_click;
  GhosttySelectionGestureBehavior triple_click;
} GhosttySelectionGestureBehaviors;
typedef struct {
  uint32_t columns;
  uint32_t cell_width;
  uint32_t padding_left;
  uint32_t screen_height;
} GhosttySelectionGestureGeometry;
typedef enum {
  GHOSTTY_SELECTION_GESTURE_AUTOSCROLL_NONE = 0,
  GHOSTTY_SELECTION_GESTURE_AUTOSCROLL_UP = 1,
  GHOSTTY_SELECTION_GESTURE_AUTOSCROLL_DOWN = 2,
  GHOSTTY_SELECTION_GESTURE_AUTOSCROLL_MAX_VALUE = 2147483647,
} GhosttySelectionGestureAutoscroll;
typedef enum {
  GHOSTTY_SELECTION_GESTURE_DATA_CLICK_COUNT = 0,
  GHOSTTY_SELECTION_GESTURE_DATA_DRAGGED = 1,
  GHOSTTY_SELECTION_GESTURE_DATA_AUTOSCROLL = 2,
  GHOSTTY_SELECTION_GESTURE_DATA_BEHAVIOR = 3,
  GHOSTTY_SELECTION_GESTURE_DATA_ANCHOR = 4,
  GHOSTTY_SELECTION_GESTURE_DATA_MAX_VALUE = 2147483647,
} GhosttySelectionGestureData;
typedef enum {
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_PRESS = 0,
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_RELEASE = 1,
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_DRAG = 2,
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_AUTOSCROLL_TICK = 3,
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_DEEP_PRESS = 4,
  GHOSTTY_SELECTION_GESTURE_EVENT_TYPE_MAX_VALUE = 2147483647,
} GhosttySelectionGestureEventType;
typedef enum {
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_REF = 0,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_POSITION = 1,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_REPEAT_DISTANCE = 2,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_TIME_NS = 3,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_REPEAT_INTERVAL_NS = 4,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_WORD_BOUNDARY_CODEPOINTS = 5,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_BEHAVIORS = 6,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_RECTANGLE = 7,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_GEOMETRY = 8,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_VIEWPORT = 9,
  GHOSTTY_SELECTION_GESTURE_EVENT_OPT_MAX_VALUE = 2147483647,
} GhosttySelectionGestureEventOption;
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_event_new(
                                    const GhosttyAllocator* allocator,
                                    GhosttySelectionGestureEvent* out_event,
                                    GhosttySelectionGestureEventType type);
__attribute__((visibility("default"))) void ghostty_selection_gesture_event_free(
                                    GhosttySelectionGestureEvent event);
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_event_set(
                                    GhosttySelectionGestureEvent event,
                                    GhosttySelectionGestureEventOption option,
                                    const void* value);
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_event(
                                    GhosttySelectionGesture gesture,
                                    GhosttyTerminal terminal,
                                    GhosttySelectionGestureEvent event,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_new(
                                    const GhosttyAllocator* allocator,
                                    GhosttySelectionGesture* out_gesture);
__attribute__((visibility("default"))) void ghostty_selection_gesture_free(
                                    GhosttySelectionGesture gesture,
                                    GhosttyTerminal terminal);
__attribute__((visibility("default"))) void ghostty_selection_gesture_reset(
                                    GhosttySelectionGesture gesture,
                                    GhosttyTerminal terminal);
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_get(
                                    GhosttySelectionGesture gesture,
                                    GhosttyTerminal terminal,
                                    GhosttySelectionGestureData data,
                                    void* value);
__attribute__((visibility("default"))) GhosttyResult ghostty_selection_gesture_get_multi(
                                    GhosttySelectionGesture gesture,
                                    GhosttyTerminal terminal,
                                    size_t count,
                                    const GhosttySelectionGestureData* keys,
                                    void** values,
                                    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_select_word(
                                    GhosttyTerminal terminal,
                                    const GhosttyTerminalSelectWordOptions* options,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_select_word_between(
                                    GhosttyTerminal terminal,
                                    const GhosttyTerminalSelectWordBetweenOptions* options,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_select_line(
                                    GhosttyTerminal terminal,
                                    const GhosttyTerminalSelectLineOptions* options,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_select_all(
                                    GhosttyTerminal terminal,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_select_output(
                                    GhosttyTerminal terminal,
                                    GhosttyGridRef ref,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_format_buf(
                                    GhosttyTerminal terminal,
                                    GhosttyTerminalSelectionFormatOptions options,
                                    uint8_t* buf,
                                    size_t buf_len,
                                    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_format_alloc(
                                    GhosttyTerminal terminal,
                                    const GhosttyAllocator* allocator,
                                    GhosttyTerminalSelectionFormatOptions options,
                                    uint8_t** out_ptr,
                                    size_t* out_len);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_adjust(
                                    GhosttyTerminal terminal,
                                    GhosttySelection* selection,
                                    GhosttySelectionAdjust adjustment);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_order(
                                    GhosttyTerminal terminal,
                                    const GhosttySelection* selection,
                                    GhosttySelectionOrder* out_order);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_ordered(
                                    GhosttyTerminal terminal,
                                    const GhosttySelection* selection,
                                    GhosttySelectionOrder desired,
                                    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_contains(
                                    GhosttyTerminal terminal,
                                    const GhosttySelection* selection,
                                    GhosttyPoint point,
                                    uint8_t* out_contains);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_selection_equal(
                                    GhosttyTerminal terminal,
                                    const GhosttySelection* a,
                                    const GhosttySelection* b,
                                    uint8_t* out_equal);

typedef uint16_t GhosttyMode;
static inline GhosttyMode ghostty_mode_new(uint16_t value, uint8_t ansi) {
    return (GhosttyMode)((value & 0x7FFF) | ((uint16_t)ansi << 15));
}
static inline uint16_t ghostty_mode_value(GhosttyMode mode) {
    return mode & 0x7FFF;
}
static inline uint8_t ghostty_mode_ansi(GhosttyMode mode) {
    return (mode >> 15) != 0;
}
typedef enum {
    GHOSTTY_MODE_REPORT_NOT_RECOGNIZED = 0,
    GHOSTTY_MODE_REPORT_SET = 1,
    GHOSTTY_MODE_REPORT_RESET = 2,
    GHOSTTY_MODE_REPORT_PERMANENTLY_SET = 3,
    GHOSTTY_MODE_REPORT_PERMANENTLY_RESET = 4,
    GHOSTTY_MODE_REPORT_MAX_VALUE = 2147483647,
} GhosttyModeReportState;
__attribute__((visibility("default"))) GhosttyResult ghostty_mode_report_encode(
    GhosttyMode mode,
    GhosttyModeReportState state,
    char* buf,
    size_t buf_len,
    size_t* out_written);
typedef enum {
    GHOSTTY_SIZE_REPORT_MODE_2048 = 0,
    GHOSTTY_SIZE_REPORT_CSI_14_T = 1,
    GHOSTTY_SIZE_REPORT_CSI_16_T = 2,
    GHOSTTY_SIZE_REPORT_CSI_18_T = 3,
    GHOSTTY_SIZE_REPORT_STYLE_MAX_VALUE = 2147483647,
} GhosttySizeReportStyle;
typedef struct {
    uint16_t rows;
    uint16_t columns;
    uint32_t cell_width;
    uint32_t cell_height;
} GhosttySizeReportSize;
__attribute__((visibility("default"))) GhosttyResult ghostty_size_report_encode(
    GhosttySizeReportStyle style,
    GhosttySizeReportSize size,
    char* buf,
    size_t buf_len,
    size_t* out_written);

typedef enum {
  GHOSTTY_KITTY_GRAPHICS_DATA_INVALID = 0,
  GHOSTTY_KITTY_GRAPHICS_DATA_PLACEMENT_ITERATOR = 1,
  GHOSTTY_KITTY_GRAPHICS_DATA_MAX_VALUE = 2147483647,
} GhosttyKittyGraphicsData;
typedef enum {
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_INVALID = 0,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_IMAGE_ID = 1,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_PLACEMENT_ID = 2,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_IS_VIRTUAL = 3,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_X_OFFSET = 4,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_Y_OFFSET = 5,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_SOURCE_X = 6,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_SOURCE_Y = 7,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_SOURCE_WIDTH = 8,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_SOURCE_HEIGHT = 9,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_COLUMNS = 10,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_ROWS = 11,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_Z = 12,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_DATA_MAX_VALUE = 2147483647,
} GhosttyKittyGraphicsPlacementData;
typedef enum {
  GHOSTTY_KITTY_PLACEMENT_LAYER_ALL = 0,
  GHOSTTY_KITTY_PLACEMENT_LAYER_BELOW_BG = 1,
  GHOSTTY_KITTY_PLACEMENT_LAYER_BELOW_TEXT = 2,
  GHOSTTY_KITTY_PLACEMENT_LAYER_ABOVE_TEXT = 3,
  GHOSTTY_KITTY_PLACEMENT_LAYER_MAX_VALUE = 2147483647,
} GhosttyKittyPlacementLayer;
typedef enum {
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_ITERATOR_OPTION_LAYER = 0,
  GHOSTTY_KITTY_GRAPHICS_PLACEMENT_ITERATOR_OPTION_MAX_VALUE = 2147483647,
} GhosttyKittyGraphicsPlacementIteratorOption;
typedef enum {
  GHOSTTY_KITTY_IMAGE_FORMAT_RGB = 0,
  GHOSTTY_KITTY_IMAGE_FORMAT_RGBA = 1,
  GHOSTTY_KITTY_IMAGE_FORMAT_PNG = 2,
  GHOSTTY_KITTY_IMAGE_FORMAT_GRAY_ALPHA = 3,
  GHOSTTY_KITTY_IMAGE_FORMAT_GRAY = 4,
  GHOSTTY_KITTY_IMAGE_FORMAT_MAX_VALUE = 2147483647,
} GhosttyKittyImageFormat;
typedef enum {
  GHOSTTY_KITTY_IMAGE_COMPRESSION_NONE = 0,
  GHOSTTY_KITTY_IMAGE_COMPRESSION_ZLIB_DEFLATE = 1,
  GHOSTTY_KITTY_IMAGE_COMPRESSION_MAX_VALUE = 2147483647,
} GhosttyKittyImageCompression;
typedef enum {
  GHOSTTY_KITTY_IMAGE_DATA_INVALID = 0,
  GHOSTTY_KITTY_IMAGE_DATA_ID = 1,
  GHOSTTY_KITTY_IMAGE_DATA_NUMBER = 2,
  GHOSTTY_KITTY_IMAGE_DATA_WIDTH = 3,
  GHOSTTY_KITTY_IMAGE_DATA_HEIGHT = 4,
  GHOSTTY_KITTY_IMAGE_DATA_FORMAT = 5,
  GHOSTTY_KITTY_IMAGE_DATA_COMPRESSION = 6,
  GHOSTTY_KITTY_IMAGE_DATA_DATA_PTR = 7,
  GHOSTTY_KITTY_IMAGE_DATA_DATA_LEN = 8,
  GHOSTTY_KITTY_IMAGE_DATA_MAX_VALUE = 2147483647,
} GhosttyKittyGraphicsImageData;
typedef struct {
  size_t size;
  uint32_t pixel_width;
  uint32_t pixel_height;
  uint32_t grid_cols;
  uint32_t grid_rows;
  int32_t viewport_col;
  int32_t viewport_row;
  uint8_t viewport_visible;
  uint32_t source_x;
  uint32_t source_y;
  uint32_t source_width;
  uint32_t source_height;
} GhosttyKittyGraphicsPlacementRenderInfo;
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_get(
    GhosttyKittyGraphics graphics,
    GhosttyKittyGraphicsData data,
    void* out);
__attribute__((visibility("default"))) GhosttyKittyGraphicsImage ghostty_kitty_graphics_image(
    GhosttyKittyGraphics graphics,
    uint32_t image_id);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_image_get(
    GhosttyKittyGraphicsImage image,
    GhosttyKittyGraphicsImageData data,
    void* out);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_image_get_multi(
    GhosttyKittyGraphicsImage image,
    size_t count,
    const GhosttyKittyGraphicsImageData* keys,
    void** values,
    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_iterator_new(
    const GhosttyAllocator* allocator,
    GhosttyKittyGraphicsPlacementIterator* out_iterator);
__attribute__((visibility("default"))) void ghostty_kitty_graphics_placement_iterator_free(
    GhosttyKittyGraphicsPlacementIterator iterator);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_iterator_set(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsPlacementIteratorOption option,
    const void* value);
__attribute__((visibility("default"))) uint8_t ghostty_kitty_graphics_placement_next(
    GhosttyKittyGraphicsPlacementIterator iterator);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_get(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsPlacementData data,
    void* out);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_get_multi(
    GhosttyKittyGraphicsPlacementIterator iterator,
    size_t count,
    const GhosttyKittyGraphicsPlacementData* keys,
    void** values,
    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_rect(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    GhosttyTerminal terminal,
    GhosttySelection* out_selection);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_pixel_size(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    GhosttyTerminal terminal,
    uint32_t* out_width,
    uint32_t* out_height);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_grid_size(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    GhosttyTerminal terminal,
    uint32_t* out_cols,
    uint32_t* out_rows);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_viewport_pos(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    GhosttyTerminal terminal,
    int32_t* out_col,
    int32_t* out_row);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_source_rect(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    uint32_t* out_x,
    uint32_t* out_y,
    uint32_t* out_width,
    uint32_t* out_height);
__attribute__((visibility("default"))) GhosttyResult ghostty_kitty_graphics_placement_render_info(
    GhosttyKittyGraphicsPlacementIterator iterator,
    GhosttyKittyGraphicsImage image,
    GhosttyTerminal terminal,
    GhosttyKittyGraphicsPlacementRenderInfo* out_info);
typedef struct {
  uint16_t cols;
  uint16_t rows;
  size_t max_scrollback;
} GhosttyTerminalOptions;
typedef enum {
  GHOSTTY_SCROLL_VIEWPORT_TOP,
  GHOSTTY_SCROLL_VIEWPORT_BOTTOM,
  GHOSTTY_SCROLL_VIEWPORT_DELTA,
  GHOSTTY_SCROLL_VIEWPORT_MAX_VALUE = 2147483647,
} GhosttyTerminalScrollViewportTag;
typedef union {
  intptr_t delta;
  uint64_t _padding[2];
} GhosttyTerminalScrollViewportValue;
typedef struct {
  GhosttyTerminalScrollViewportTag tag;
  GhosttyTerminalScrollViewportValue value;
} GhosttyTerminalScrollViewport;
typedef enum {
  GHOSTTY_TERMINAL_SCREEN_PRIMARY = 0,
  GHOSTTY_TERMINAL_SCREEN_ALTERNATE = 1,
  GHOSTTY_TERMINAL_SCREEN_MAX_VALUE = 2147483647,
} GhosttyTerminalScreen;
typedef struct {
  uint64_t total;
  uint64_t offset;
  uint64_t len;
} GhosttyTerminalScrollbar;
typedef void (*GhosttyTerminalBellFn)(GhosttyTerminal terminal,
                                      void* userdata);
typedef uint8_t (*GhosttyTerminalColorSchemeFn)(GhosttyTerminal terminal,
                                             void* userdata,
                                             GhosttyColorScheme* out_scheme);
typedef uint8_t (*GhosttyTerminalDeviceAttributesFn)(GhosttyTerminal terminal,
                                                   void* userdata,
                                                   GhosttyDeviceAttributes* out_attrs);
typedef GhosttyString (*GhosttyTerminalEnquiryFn)(GhosttyTerminal terminal,
                                                   void* userdata);
typedef uint8_t (*GhosttyTerminalSizeFn)(GhosttyTerminal terminal,
                                      void* userdata,
                                      GhosttySizeReportSize* out_size);
typedef void (*GhosttyTerminalTitleChangedFn)(GhosttyTerminal terminal,
                                              void* userdata);
typedef void (*GhosttyTerminalWritePtyFn)(GhosttyTerminal terminal,
                                          void* userdata,
                                          const uint8_t* data,
                                          size_t len);
typedef GhosttyString (*GhosttyTerminalXtversionFn)(GhosttyTerminal terminal,
                                                     void* userdata);
typedef enum {
  GHOSTTY_TERMINAL_OPT_USERDATA = 0,
  GHOSTTY_TERMINAL_OPT_WRITE_PTY = 1,
  GHOSTTY_TERMINAL_OPT_BELL = 2,
  GHOSTTY_TERMINAL_OPT_ENQUIRY = 3,
  GHOSTTY_TERMINAL_OPT_XTVERSION = 4,
  GHOSTTY_TERMINAL_OPT_TITLE_CHANGED = 5,
  GHOSTTY_TERMINAL_OPT_SIZE = 6,
  GHOSTTY_TERMINAL_OPT_COLOR_SCHEME = 7,
  GHOSTTY_TERMINAL_OPT_DEVICE_ATTRIBUTES = 8,
  GHOSTTY_TERMINAL_OPT_TITLE = 9,
  GHOSTTY_TERMINAL_OPT_PWD = 10,
  GHOSTTY_TERMINAL_OPT_COLOR_FOREGROUND = 11,
  GHOSTTY_TERMINAL_OPT_COLOR_BACKGROUND = 12,
  GHOSTTY_TERMINAL_OPT_COLOR_CURSOR = 13,
  GHOSTTY_TERMINAL_OPT_COLOR_PALETTE = 14,
  GHOSTTY_TERMINAL_OPT_KITTY_IMAGE_STORAGE_LIMIT = 15,
  GHOSTTY_TERMINAL_OPT_KITTY_IMAGE_MEDIUM_FILE = 16,
  GHOSTTY_TERMINAL_OPT_KITTY_IMAGE_MEDIUM_TEMP_FILE = 17,
  GHOSTTY_TERMINAL_OPT_KITTY_IMAGE_MEDIUM_SHARED_MEM = 18,
  GHOSTTY_TERMINAL_OPT_APC_MAX_BYTES = 19,
  GHOSTTY_TERMINAL_OPT_APC_MAX_BYTES_KITTY = 20,
  GHOSTTY_TERMINAL_OPT_SELECTION = 21,
  GHOSTTY_TERMINAL_OPT_MAX_VALUE = 2147483647,
} GhosttyTerminalOption;
typedef enum {
  GHOSTTY_TERMINAL_DATA_INVALID = 0,
  GHOSTTY_TERMINAL_DATA_COLS = 1,
  GHOSTTY_TERMINAL_DATA_ROWS = 2,
  GHOSTTY_TERMINAL_DATA_CURSOR_X = 3,
  GHOSTTY_TERMINAL_DATA_CURSOR_Y = 4,
  GHOSTTY_TERMINAL_DATA_CURSOR_PENDING_WRAP = 5,
  GHOSTTY_TERMINAL_DATA_ACTIVE_SCREEN = 6,
  GHOSTTY_TERMINAL_DATA_CURSOR_VISIBLE = 7,
  GHOSTTY_TERMINAL_DATA_KITTY_KEYBOARD_FLAGS = 8,
  GHOSTTY_TERMINAL_DATA_SCROLLBAR = 9,
  GHOSTTY_TERMINAL_DATA_CURSOR_STYLE = 10,
  GHOSTTY_TERMINAL_DATA_MOUSE_TRACKING = 11,
  GHOSTTY_TERMINAL_DATA_TITLE = 12,
  GHOSTTY_TERMINAL_DATA_PWD = 13,
  GHOSTTY_TERMINAL_DATA_TOTAL_ROWS = 14,
  GHOSTTY_TERMINAL_DATA_SCROLLBACK_ROWS = 15,
  GHOSTTY_TERMINAL_DATA_WIDTH_PX = 16,
  GHOSTTY_TERMINAL_DATA_HEIGHT_PX = 17,
  GHOSTTY_TERMINAL_DATA_COLOR_FOREGROUND = 18,
  GHOSTTY_TERMINAL_DATA_COLOR_BACKGROUND = 19,
  GHOSTTY_TERMINAL_DATA_COLOR_CURSOR = 20,
  GHOSTTY_TERMINAL_DATA_COLOR_PALETTE = 21,
  GHOSTTY_TERMINAL_DATA_COLOR_FOREGROUND_DEFAULT = 22,
  GHOSTTY_TERMINAL_DATA_COLOR_BACKGROUND_DEFAULT = 23,
  GHOSTTY_TERMINAL_DATA_COLOR_CURSOR_DEFAULT = 24,
  GHOSTTY_TERMINAL_DATA_COLOR_PALETTE_DEFAULT = 25,
  GHOSTTY_TERMINAL_DATA_KITTY_IMAGE_STORAGE_LIMIT = 26,
  GHOSTTY_TERMINAL_DATA_KITTY_IMAGE_MEDIUM_FILE = 27,
  GHOSTTY_TERMINAL_DATA_KITTY_IMAGE_MEDIUM_TEMP_FILE = 28,
  GHOSTTY_TERMINAL_DATA_KITTY_IMAGE_MEDIUM_SHARED_MEM = 29,
  GHOSTTY_TERMINAL_DATA_KITTY_GRAPHICS = 30,
  GHOSTTY_TERMINAL_DATA_SELECTION = 31,
  GHOSTTY_TERMINAL_DATA_VIEWPORT_ACTIVE = 32,
  GHOSTTY_TERMINAL_DATA_MAX_VALUE = 2147483647,
} GhosttyTerminalData;
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_new(const GhosttyAllocator* allocator,
                                   GhosttyTerminal* terminal,
                                   GhosttyTerminalOptions options);
__attribute__((visibility("default"))) void ghostty_terminal_free(GhosttyTerminal terminal);
__attribute__((visibility("default"))) void ghostty_terminal_reset(GhosttyTerminal terminal);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_resize(GhosttyTerminal terminal,
                                      uint16_t cols,
                                      uint16_t rows,
                                      uint32_t cell_width_px,
                                      uint32_t cell_height_px);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_set(GhosttyTerminal terminal,
                                   GhosttyTerminalOption option,
                                   const void* value);
__attribute__((visibility("default"))) void ghostty_terminal_vt_write(GhosttyTerminal terminal,
                                const uint8_t* data,
                                size_t len);
__attribute__((visibility("default"))) void ghostty_terminal_scroll_viewport(GhosttyTerminal terminal,
                                       GhosttyTerminalScrollViewport behavior);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_mode_get(GhosttyTerminal terminal,
                                        GhosttyMode mode,
                                        uint8_t* out_value);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_mode_set(GhosttyTerminal terminal,
                                         GhosttyMode mode,
                                         uint8_t value);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_get(GhosttyTerminal terminal,
                                    GhosttyTerminalData data,
                                    void *out);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_get_multi(GhosttyTerminal terminal,
                                    size_t count,
                                    const GhosttyTerminalData* keys,
                                    void** values,
                                    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_grid_ref(GhosttyTerminal terminal,
                                        GhosttyPoint point,
                                        GhosttyGridRef *out_ref);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_grid_ref_track(
    GhosttyTerminal terminal,
    GhosttyPoint point,
    GhosttyTrackedGridRef *out_ref);
__attribute__((visibility("default"))) GhosttyResult ghostty_terminal_point_from_grid_ref(
    GhosttyTerminal terminal,
    const GhosttyGridRef *ref,
    GhosttyPointTag tag,
    GhosttyPointCoordinate *out);
typedef struct {
  size_t size;
  uint8_t cursor;
  uint8_t style;
  uint8_t hyperlink;
  uint8_t protection;
  uint8_t kitty_keyboard;
  uint8_t charsets;
} GhosttyFormatterScreenExtra;
typedef struct {
  size_t size;
  uint8_t palette;
  uint8_t modes;
  uint8_t scrolling_region;
  uint8_t tabstops;
  uint8_t pwd;
  uint8_t keyboard;
  GhosttyFormatterScreenExtra screen;
} GhosttyFormatterTerminalExtra;
typedef struct {
  size_t size;
  GhosttyFormatterFormat emit;
  uint8_t unwrap;
  uint8_t trim;
  GhosttyFormatterTerminalExtra extra;
  const GhosttySelection *selection;
} GhosttyFormatterTerminalOptions;
__attribute__((visibility("default"))) GhosttyResult ghostty_formatter_terminal_new(
    const GhosttyAllocator* allocator,
    GhosttyFormatter* formatter,
    GhosttyTerminal terminal,
    GhosttyFormatterTerminalOptions options);
__attribute__((visibility("default"))) GhosttyResult ghostty_formatter_format_buf(GhosttyFormatter formatter,
                                           uint8_t* buf,
                                           size_t buf_len,
                                           size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_formatter_format_alloc(GhosttyFormatter formatter,
                                             const GhosttyAllocator* allocator,
                                             uint8_t** out_ptr,
                                             size_t* out_len);
__attribute__((visibility("default"))) void ghostty_formatter_free(GhosttyFormatter formatter);
typedef enum {
  GHOSTTY_RENDER_STATE_DIRTY_FALSE = 0,
  GHOSTTY_RENDER_STATE_DIRTY_PARTIAL = 1,
  GHOSTTY_RENDER_STATE_DIRTY_FULL = 2,
  GHOSTTY_RENDER_STATE_DIRTY_MAX_VALUE = 2147483647,
} GhosttyRenderStateDirty;
typedef enum {
  GHOSTTY_RENDER_STATE_CURSOR_VISUAL_STYLE_BAR = 0,
  GHOSTTY_RENDER_STATE_CURSOR_VISUAL_STYLE_BLOCK = 1,
  GHOSTTY_RENDER_STATE_CURSOR_VISUAL_STYLE_UNDERLINE = 2,
  GHOSTTY_RENDER_STATE_CURSOR_VISUAL_STYLE_BLOCK_HOLLOW = 3,
  GHOSTTY_RENDER_STATE_CURSOR_VISUAL_STYLE_MAX_VALUE = 2147483647,
} GhosttyRenderStateCursorVisualStyle;
typedef enum {
  GHOSTTY_RENDER_STATE_DATA_INVALID = 0,
  GHOSTTY_RENDER_STATE_DATA_COLS = 1,
  GHOSTTY_RENDER_STATE_DATA_ROWS = 2,
  GHOSTTY_RENDER_STATE_DATA_DIRTY = 3,
  GHOSTTY_RENDER_STATE_DATA_ROW_ITERATOR = 4,
  GHOSTTY_RENDER_STATE_DATA_COLOR_BACKGROUND = 5,
  GHOSTTY_RENDER_STATE_DATA_COLOR_FOREGROUND = 6,
  GHOSTTY_RENDER_STATE_DATA_COLOR_CURSOR = 7,
  GHOSTTY_RENDER_STATE_DATA_COLOR_CURSOR_HAS_VALUE = 8,
  GHOSTTY_RENDER_STATE_DATA_COLOR_PALETTE = 9,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VISUAL_STYLE = 10,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VISIBLE = 11,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_BLINKING = 12,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_PASSWORD_INPUT = 13,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_HAS_VALUE = 14,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_X = 15,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_Y = 16,
  GHOSTTY_RENDER_STATE_DATA_CURSOR_VIEWPORT_WIDE_TAIL = 17,
  GHOSTTY_RENDER_STATE_DATA_MAX_VALUE = 2147483647,
} GhosttyRenderStateData;
typedef enum {
  GHOSTTY_RENDER_STATE_OPTION_DIRTY = 0,
  GHOSTTY_RENDER_STATE_OPTION_MAX_VALUE = 2147483647,
} GhosttyRenderStateOption;
typedef enum {
  GHOSTTY_RENDER_STATE_ROW_DATA_INVALID = 0,
  GHOSTTY_RENDER_STATE_ROW_DATA_DIRTY = 1,
  GHOSTTY_RENDER_STATE_ROW_DATA_RAW = 2,
  GHOSTTY_RENDER_STATE_ROW_DATA_CELLS = 3,
  GHOSTTY_RENDER_STATE_ROW_DATA_SELECTION = 4,
  GHOSTTY_RENDER_STATE_ROW_DATA_MAX_VALUE = 2147483647,
} GhosttyRenderStateRowData;
typedef enum {
  GHOSTTY_RENDER_STATE_ROW_OPTION_DIRTY = 0,
  GHOSTTY_RENDER_STATE_ROW_OPTION_MAX_VALUE = 2147483647,
} GhosttyRenderStateRowOption;
typedef struct {
  size_t size;
  uint16_t start_x;
  uint16_t end_x;
} GhosttyRenderStateRowSelection;
typedef struct {
  size_t size;
  GhosttyColorRgb background;
  GhosttyColorRgb foreground;
  GhosttyColorRgb cursor;
  uint8_t cursor_has_value;
  GhosttyColorRgb palette[256];
} GhosttyRenderStateColors;
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_new(const GhosttyAllocator* allocator,
                                       GhosttyRenderState* state);
__attribute__((visibility("default"))) void ghostty_render_state_free(GhosttyRenderState state);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_update(GhosttyRenderState state,
                                          GhosttyTerminal terminal);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_get(GhosttyRenderState state,
                                        GhosttyRenderStateData data,
                                        void* out);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_get_multi(
    GhosttyRenderState state,
    size_t count,
    const GhosttyRenderStateData* keys,
    void** values,
    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_set(GhosttyRenderState state,
                                       GhosttyRenderStateOption option,
                                       const void* value);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_colors_get(GhosttyRenderState state,
                                              GhosttyRenderStateColors* out_colors);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_iterator_new(
    const GhosttyAllocator* allocator,
    GhosttyRenderStateRowIterator* out_iterator);
__attribute__((visibility("default"))) void ghostty_render_state_row_iterator_free(GhosttyRenderStateRowIterator iterator);
__attribute__((visibility("default"))) uint8_t ghostty_render_state_row_iterator_next(GhosttyRenderStateRowIterator iterator);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_get(
    GhosttyRenderStateRowIterator iterator,
    GhosttyRenderStateRowData data,
    void* out);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_get_multi(
    GhosttyRenderStateRowIterator iterator,
    size_t count,
    const GhosttyRenderStateRowData* keys,
    void** values,
    size_t* out_written);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_set(
    GhosttyRenderStateRowIterator iterator,
    GhosttyRenderStateRowOption option,
    const void* value);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_cells_new(
    const GhosttyAllocator* allocator,
    GhosttyRenderStateRowCells* out_cells);
typedef enum {
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_INVALID = 0,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_RAW = 1,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_STYLE = 2,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_LEN = 3,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_BUF = 4,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_BG_COLOR = 5,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_FG_COLOR = 6,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_SELECTED = 7,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_HAS_STYLING = 8,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_GRAPHEMES_UTF8 = 9,
  GHOSTTY_RENDER_STATE_ROW_CELLS_DATA_MAX_VALUE = 2147483647,
} GhosttyRenderStateRowCellsData;
__attribute__((visibility("default"))) uint8_t ghostty_render_state_row_cells_next(GhosttyRenderStateRowCells cells);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_cells_select(
    GhosttyRenderStateRowCells cells, uint16_t x);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_cells_get(
    GhosttyRenderStateRowCells cells,
    GhosttyRenderStateRowCellsData data,
    void* out);
__attribute__((visibility("default"))) GhosttyResult ghostty_render_state_row_cells_get_multi(
    GhosttyRenderStateRowCells cells,
    size_t count,
    const GhosttyRenderStateRowCellsData* keys,
    void** values,
    size_t* out_written);
__attribute__((visibility("default"))) void ghostty_render_state_row_cells_free(GhosttyRenderStateRowCells cells);
__attribute__((visibility("default"))) void ghostty_tracked_grid_ref_free(GhosttyTrackedGridRef ref);
__attribute__((visibility("default"))) uint8_t ghostty_tracked_grid_ref_has_value(
    GhosttyTrackedGridRef ref);
__attribute__((visibility("default"))) GhosttyResult ghostty_tracked_grid_ref_point(
    GhosttyTrackedGridRef ref,
    GhosttyPointTag tag,
    GhosttyPointCoordinate *out_point);
__attribute__((visibility("default"))) GhosttyResult ghostty_tracked_grid_ref_set(
    GhosttyTrackedGridRef ref,
    GhosttyTerminal terminal,
    GhosttyPoint point);
__attribute__((visibility("default"))) GhosttyResult ghostty_tracked_grid_ref_snapshot(
    GhosttyTrackedGridRef ref,
    GhosttyGridRef *out_ref);
typedef enum {
  GHOSTTY_OSC_COMMAND_INVALID = 0,
  GHOSTTY_OSC_COMMAND_CHANGE_WINDOW_TITLE = 1,
  GHOSTTY_OSC_COMMAND_CHANGE_WINDOW_ICON = 2,
  GHOSTTY_OSC_COMMAND_SEMANTIC_PROMPT = 3,
  GHOSTTY_OSC_COMMAND_CLIPBOARD_CONTENTS = 4,
  GHOSTTY_OSC_COMMAND_REPORT_PWD = 5,
  GHOSTTY_OSC_COMMAND_MOUSE_SHAPE = 6,
  GHOSTTY_OSC_COMMAND_COLOR_OPERATION = 7,
  GHOSTTY_OSC_COMMAND_KITTY_COLOR_PROTOCOL = 8,
  GHOSTTY_OSC_COMMAND_SHOW_DESKTOP_NOTIFICATION = 9,
  GHOSTTY_OSC_COMMAND_HYPERLINK_START = 10,
  GHOSTTY_OSC_COMMAND_HYPERLINK_END = 11,
  GHOSTTY_OSC_COMMAND_CONEMU_SLEEP = 12,
  GHOSTTY_OSC_COMMAND_CONEMU_SHOW_MESSAGE_BOX = 13,
  GHOSTTY_OSC_COMMAND_CONEMU_CHANGE_TAB_TITLE = 14,
  GHOSTTY_OSC_COMMAND_CONEMU_PROGRESS_REPORT = 15,
  GHOSTTY_OSC_COMMAND_CONEMU_WAIT_INPUT = 16,
  GHOSTTY_OSC_COMMAND_CONEMU_GUIMACRO = 17,
  GHOSTTY_OSC_COMMAND_CONEMU_RUN_PROCESS = 18,
  GHOSTTY_OSC_COMMAND_CONEMU_OUTPUT_ENVIRONMENT_VARIABLE = 19,
  GHOSTTY_OSC_COMMAND_CONEMU_XTERM_EMULATION = 20,
  GHOSTTY_OSC_COMMAND_CONEMU_COMMENT = 21,
  GHOSTTY_OSC_COMMAND_KITTY_TEXT_SIZING = 22,
  GHOSTTY_OSC_COMMAND_TYPE_MAX_VALUE = 2147483647,
} GhosttyOscCommandType;
typedef enum {
  GHOSTTY_OSC_DATA_INVALID = 0,
  GHOSTTY_OSC_DATA_CHANGE_WINDOW_TITLE_STR = 1,
  GHOSTTY_OSC_DATA_MAX_VALUE = 2147483647,
} GhosttyOscCommandData;
__attribute__((visibility("default"))) GhosttyResult ghostty_osc_new(const GhosttyAllocator *allocator, GhosttyOscParser *parser);
__attribute__((visibility("default"))) void ghostty_osc_free(GhosttyOscParser parser);
__attribute__((visibility("default"))) void ghostty_osc_reset(GhosttyOscParser parser);
__attribute__((visibility("default"))) void ghostty_osc_next(GhosttyOscParser parser, uint8_t byte);
__attribute__((visibility("default"))) GhosttyOscCommand ghostty_osc_end(GhosttyOscParser parser, uint8_t terminator);
__attribute__((visibility("default"))) GhosttyOscCommandType ghostty_osc_command_type(GhosttyOscCommand command);
__attribute__((visibility("default"))) uint8_t ghostty_osc_command_data(GhosttyOscCommand command, GhosttyOscCommandData data, void *out);
typedef enum {
  GHOSTTY_SGR_ATTR_UNSET = 0,
  GHOSTTY_SGR_ATTR_UNKNOWN = 1,
  GHOSTTY_SGR_ATTR_BOLD = 2,
  GHOSTTY_SGR_ATTR_RESET_BOLD = 3,
  GHOSTTY_SGR_ATTR_ITALIC = 4,
  GHOSTTY_SGR_ATTR_RESET_ITALIC = 5,
  GHOSTTY_SGR_ATTR_FAINT = 6,
  GHOSTTY_SGR_ATTR_UNDERLINE = 7,
  GHOSTTY_SGR_ATTR_UNDERLINE_COLOR = 8,
  GHOSTTY_SGR_ATTR_UNDERLINE_COLOR_256 = 9,
  GHOSTTY_SGR_ATTR_RESET_UNDERLINE_COLOR = 10,
  GHOSTTY_SGR_ATTR_OVERLINE = 11,
  GHOSTTY_SGR_ATTR_RESET_OVERLINE = 12,
  GHOSTTY_SGR_ATTR_BLINK = 13,
  GHOSTTY_SGR_ATTR_RESET_BLINK = 14,
  GHOSTTY_SGR_ATTR_INVERSE = 15,
  GHOSTTY_SGR_ATTR_RESET_INVERSE = 16,
  GHOSTTY_SGR_ATTR_INVISIBLE = 17,
  GHOSTTY_SGR_ATTR_RESET_INVISIBLE = 18,
  GHOSTTY_SGR_ATTR_STRIKETHROUGH = 19,
  GHOSTTY_SGR_ATTR_RESET_STRIKETHROUGH = 20,
  GHOSTTY_SGR_ATTR_DIRECT_COLOR_FG = 21,
  GHOSTTY_SGR_ATTR_DIRECT_COLOR_BG = 22,
  GHOSTTY_SGR_ATTR_BG_8 = 23,
  GHOSTTY_SGR_ATTR_FG_8 = 24,
  GHOSTTY_SGR_ATTR_RESET_FG = 25,
  GHOSTTY_SGR_ATTR_RESET_BG = 26,
  GHOSTTY_SGR_ATTR_BRIGHT_BG_8 = 27,
  GHOSTTY_SGR_ATTR_BRIGHT_FG_8 = 28,
  GHOSTTY_SGR_ATTR_BG_256 = 29,
  GHOSTTY_SGR_ATTR_FG_256 = 30,
  GHOSTTY_SGR_ATTR_MAX_VALUE = 2147483647,
} GhosttySgrAttributeTag;
typedef enum {
  GHOSTTY_SGR_UNDERLINE_NONE = 0,
  GHOSTTY_SGR_UNDERLINE_SINGLE = 1,
  GHOSTTY_SGR_UNDERLINE_DOUBLE = 2,
  GHOSTTY_SGR_UNDERLINE_CURLY = 3,
  GHOSTTY_SGR_UNDERLINE_DOTTED = 4,
  GHOSTTY_SGR_UNDERLINE_DASHED = 5,
  GHOSTTY_SGR_UNDERLINE_MAX_VALUE = 2147483647,
} GhosttySgrUnderline;
typedef struct {
  const uint16_t* full_ptr;
  size_t full_len;
  const uint16_t* partial_ptr;
  size_t partial_len;
} GhosttySgrUnknown;
typedef union {
  GhosttySgrUnknown unknown;
  GhosttySgrUnderline underline;
  GhosttyColorRgb underline_color;
  GhosttyColorPaletteIndex underline_color_256;
  GhosttyColorRgb direct_color_fg;
  GhosttyColorRgb direct_color_bg;
  GhosttyColorPaletteIndex bg_8;
  GhosttyColorPaletteIndex fg_8;
  GhosttyColorPaletteIndex bright_bg_8;
  GhosttyColorPaletteIndex bright_fg_8;
  GhosttyColorPaletteIndex bg_256;
  GhosttyColorPaletteIndex fg_256;
  uint64_t _padding[8];
} GhosttySgrAttributeValue;
typedef struct {
  GhosttySgrAttributeTag tag;
  GhosttySgrAttributeValue value;
} GhosttySgrAttribute;
__attribute__((visibility("default"))) GhosttyResult ghostty_sgr_new(const GhosttyAllocator* allocator,
                              GhosttySgrParser* parser);
__attribute__((visibility("default"))) void ghostty_sgr_free(GhosttySgrParser parser);
__attribute__((visibility("default"))) void ghostty_sgr_reset(GhosttySgrParser parser);
__attribute__((visibility("default"))) GhosttyResult ghostty_sgr_set_params(GhosttySgrParser parser,
                                     const uint16_t* params,
                                     const char* separators,
                                     size_t len);
__attribute__((visibility("default"))) uint8_t ghostty_sgr_next(GhosttySgrParser parser, GhosttySgrAttribute* attr);
__attribute__((visibility("default"))) size_t ghostty_sgr_unknown_full(GhosttySgrUnknown unknown,
                                const uint16_t** ptr);
__attribute__((visibility("default"))) size_t ghostty_sgr_unknown_partial(GhosttySgrUnknown unknown,
                                   const uint16_t** ptr);
__attribute__((visibility("default"))) GhosttySgrAttributeTag ghostty_sgr_attribute_tag(GhosttySgrAttribute attr);
__attribute__((visibility("default"))) GhosttySgrAttributeValue* ghostty_sgr_attribute_value(
    GhosttySgrAttribute* attr);

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t* data;
    size_t data_len;
} GhosttySysImage;
typedef enum {
    GHOSTTY_SYS_LOG_LEVEL_ERROR = 0,
    GHOSTTY_SYS_LOG_LEVEL_WARNING = 1,
    GHOSTTY_SYS_LOG_LEVEL_INFO = 2,
    GHOSTTY_SYS_LOG_LEVEL_DEBUG = 3,
    GHOSTTY_SYS_LOG_LEVEL_MAX_VALUE = 2147483647,
} GhosttySysLogLevel;
typedef void (*GhosttySysLogFn)(
    void* userdata,
    GhosttySysLogLevel level,
    const uint8_t* scope,
    size_t scope_len,
    const uint8_t* message,
    size_t message_len);
typedef uint8_t (*GhosttySysDecodePngFn)(
    void* userdata,
    const GhosttyAllocator* allocator,
    const uint8_t* data,
    size_t data_len,
    GhosttySysImage* out);
typedef enum {
    GHOSTTY_SYS_OPT_USERDATA = 0,
    GHOSTTY_SYS_OPT_DECODE_PNG = 1,
    GHOSTTY_SYS_OPT_LOG = 2,
    GHOSTTY_SYS_OPT_MAX_VALUE = 2147483647,
} GhosttySysOption;
__attribute__((visibility("default"))) GhosttyResult ghostty_sys_set(GhosttySysOption option,
                                           const void* value);
__attribute__((visibility("default"))) void ghostty_sys_log_stderr(void* userdata,
                                         GhosttySysLogLevel level,
                                         const uint8_t* scope,
                                         size_t scope_len,
                                         const uint8_t* message,
                                         size_t message_len);
typedef struct GhosttyKeyEventImpl *GhosttyKeyEvent;
typedef enum {
    GHOSTTY_KEY_ACTION_RELEASE = 0,
    GHOSTTY_KEY_ACTION_PRESS = 1,
    GHOSTTY_KEY_ACTION_REPEAT = 2,
    GHOSTTY_KEY_ACTION_MAX_VALUE = 2147483647,
} GhosttyKeyAction;
typedef uint16_t GhosttyMods;
typedef enum {
    GHOSTTY_KEY_UNIDENTIFIED = 0,
    GHOSTTY_KEY_BACKQUOTE,
    GHOSTTY_KEY_BACKSLASH,
    GHOSTTY_KEY_BRACKET_LEFT,
    GHOSTTY_KEY_BRACKET_RIGHT,
    GHOSTTY_KEY_COMMA,
    GHOSTTY_KEY_DIGIT_0,
    GHOSTTY_KEY_DIGIT_1,
    GHOSTTY_KEY_DIGIT_2,
    GHOSTTY_KEY_DIGIT_3,
    GHOSTTY_KEY_DIGIT_4,
    GHOSTTY_KEY_DIGIT_5,
    GHOSTTY_KEY_DIGIT_6,
    GHOSTTY_KEY_DIGIT_7,
    GHOSTTY_KEY_DIGIT_8,
    GHOSTTY_KEY_DIGIT_9,
    GHOSTTY_KEY_EQUAL,
    GHOSTTY_KEY_INTL_BACKSLASH,
    GHOSTTY_KEY_INTL_RO,
    GHOSTTY_KEY_INTL_YEN,
    GHOSTTY_KEY_A,
    GHOSTTY_KEY_B,
    GHOSTTY_KEY_C,
    GHOSTTY_KEY_D,
    GHOSTTY_KEY_E,
    GHOSTTY_KEY_F,
    GHOSTTY_KEY_G,
    GHOSTTY_KEY_H,
    GHOSTTY_KEY_I,
    GHOSTTY_KEY_J,
    GHOSTTY_KEY_K,
    GHOSTTY_KEY_L,
    GHOSTTY_KEY_M,
    GHOSTTY_KEY_N,
    GHOSTTY_KEY_O,
    GHOSTTY_KEY_P,
    GHOSTTY_KEY_Q,
    GHOSTTY_KEY_R,
    GHOSTTY_KEY_S,
    GHOSTTY_KEY_T,
    GHOSTTY_KEY_U,
    GHOSTTY_KEY_V,
    GHOSTTY_KEY_W,
    GHOSTTY_KEY_X,
    GHOSTTY_KEY_Y,
    GHOSTTY_KEY_Z,
    GHOSTTY_KEY_MINUS,
    GHOSTTY_KEY_PERIOD,
    GHOSTTY_KEY_QUOTE,
    GHOSTTY_KEY_SEMICOLON,
    GHOSTTY_KEY_SLASH,
    GHOSTTY_KEY_ALT_LEFT,
    GHOSTTY_KEY_ALT_RIGHT,
    GHOSTTY_KEY_BACKSPACE,
    GHOSTTY_KEY_CAPS_LOCK,
    GHOSTTY_KEY_CONTEXT_MENU,
    GHOSTTY_KEY_CONTROL_LEFT,
    GHOSTTY_KEY_CONTROL_RIGHT,
    GHOSTTY_KEY_ENTER,
    GHOSTTY_KEY_META_LEFT,
    GHOSTTY_KEY_META_RIGHT,
    GHOSTTY_KEY_SHIFT_LEFT,
    GHOSTTY_KEY_SHIFT_RIGHT,
    GHOSTTY_KEY_SPACE,
    GHOSTTY_KEY_TAB,
    GHOSTTY_KEY_CONVERT,
    GHOSTTY_KEY_KANA_MODE,
    GHOSTTY_KEY_NON_CONVERT,
    GHOSTTY_KEY_DELETE,
    GHOSTTY_KEY_END,
    GHOSTTY_KEY_HELP,
    GHOSTTY_KEY_HOME,
    GHOSTTY_KEY_INSERT,
    GHOSTTY_KEY_PAGE_DOWN,
    GHOSTTY_KEY_PAGE_UP,
    GHOSTTY_KEY_ARROW_DOWN,
    GHOSTTY_KEY_ARROW_LEFT,
    GHOSTTY_KEY_ARROW_RIGHT,
    GHOSTTY_KEY_ARROW_UP,
    GHOSTTY_KEY_NUM_LOCK,
    GHOSTTY_KEY_NUMPAD_0,
    GHOSTTY_KEY_NUMPAD_1,
    GHOSTTY_KEY_NUMPAD_2,
    GHOSTTY_KEY_NUMPAD_3,
    GHOSTTY_KEY_NUMPAD_4,
    GHOSTTY_KEY_NUMPAD_5,
    GHOSTTY_KEY_NUMPAD_6,
    GHOSTTY_KEY_NUMPAD_7,
    GHOSTTY_KEY_NUMPAD_8,
    GHOSTTY_KEY_NUMPAD_9,
    GHOSTTY_KEY_NUMPAD_ADD,
    GHOSTTY_KEY_NUMPAD_BACKSPACE,
    GHOSTTY_KEY_NUMPAD_CLEAR,
    GHOSTTY_KEY_NUMPAD_CLEAR_ENTRY,
    GHOSTTY_KEY_NUMPAD_COMMA,
    GHOSTTY_KEY_NUMPAD_DECIMAL,
    GHOSTTY_KEY_NUMPAD_DIVIDE,
    GHOSTTY_KEY_NUMPAD_ENTER,
    GHOSTTY_KEY_NUMPAD_EQUAL,
    GHOSTTY_KEY_NUMPAD_MEMORY_ADD,
    GHOSTTY_KEY_NUMPAD_MEMORY_CLEAR,
    GHOSTTY_KEY_NUMPAD_MEMORY_RECALL,
    GHOSTTY_KEY_NUMPAD_MEMORY_STORE,
    GHOSTTY_KEY_NUMPAD_MEMORY_SUBTRACT,
    GHOSTTY_KEY_NUMPAD_MULTIPLY,
    GHOSTTY_KEY_NUMPAD_PAREN_LEFT,
    GHOSTTY_KEY_NUMPAD_PAREN_RIGHT,
    GHOSTTY_KEY_NUMPAD_SUBTRACT,
    GHOSTTY_KEY_NUMPAD_SEPARATOR,
    GHOSTTY_KEY_NUMPAD_UP,
    GHOSTTY_KEY_NUMPAD_DOWN,
    GHOSTTY_KEY_NUMPAD_RIGHT,
    GHOSTTY_KEY_NUMPAD_LEFT,
    GHOSTTY_KEY_NUMPAD_BEGIN,
    GHOSTTY_KEY_NUMPAD_HOME,
    GHOSTTY_KEY_NUMPAD_END,
    GHOSTTY_KEY_NUMPAD_INSERT,
    GHOSTTY_KEY_NUMPAD_DELETE,
    GHOSTTY_KEY_NUMPAD_PAGE_UP,
    GHOSTTY_KEY_NUMPAD_PAGE_DOWN,
    GHOSTTY_KEY_ESCAPE,
    GHOSTTY_KEY_F1,
    GHOSTTY_KEY_F2,
    GHOSTTY_KEY_F3,
    GHOSTTY_KEY_F4,
    GHOSTTY_KEY_F5,
    GHOSTTY_KEY_F6,
    GHOSTTY_KEY_F7,
    GHOSTTY_KEY_F8,
    GHOSTTY_KEY_F9,
    GHOSTTY_KEY_F10,
    GHOSTTY_KEY_F11,
    GHOSTTY_KEY_F12,
    GHOSTTY_KEY_F13,
    GHOSTTY_KEY_F14,
    GHOSTTY_KEY_F15,
    GHOSTTY_KEY_F16,
    GHOSTTY_KEY_F17,
    GHOSTTY_KEY_F18,
    GHOSTTY_KEY_F19,
    GHOSTTY_KEY_F20,
    GHOSTTY_KEY_F21,
    GHOSTTY_KEY_F22,
    GHOSTTY_KEY_F23,
    GHOSTTY_KEY_F24,
    GHOSTTY_KEY_F25,
    GHOSTTY_KEY_FN,
    GHOSTTY_KEY_FN_LOCK,
    GHOSTTY_KEY_PRINT_SCREEN,
    GHOSTTY_KEY_SCROLL_LOCK,
    GHOSTTY_KEY_PAUSE,
    GHOSTTY_KEY_BROWSER_BACK,
    GHOSTTY_KEY_BROWSER_FAVORITES,
    GHOSTTY_KEY_BROWSER_FORWARD,
    GHOSTTY_KEY_BROWSER_HOME,
    GHOSTTY_KEY_BROWSER_REFRESH,
    GHOSTTY_KEY_BROWSER_SEARCH,
    GHOSTTY_KEY_BROWSER_STOP,
    GHOSTTY_KEY_EJECT,
    GHOSTTY_KEY_LAUNCH_APP_1,
    GHOSTTY_KEY_LAUNCH_APP_2,
    GHOSTTY_KEY_LAUNCH_MAIL,
    GHOSTTY_KEY_MEDIA_PLAY_PAUSE,
    GHOSTTY_KEY_MEDIA_SELECT,
    GHOSTTY_KEY_MEDIA_STOP,
    GHOSTTY_KEY_MEDIA_TRACK_NEXT,
    GHOSTTY_KEY_MEDIA_TRACK_PREVIOUS,
    GHOSTTY_KEY_POWER,
    GHOSTTY_KEY_SLEEP,
    GHOSTTY_KEY_AUDIO_VOLUME_DOWN,
    GHOSTTY_KEY_AUDIO_VOLUME_MUTE,
    GHOSTTY_KEY_AUDIO_VOLUME_UP,
    GHOSTTY_KEY_WAKE_UP,
    GHOSTTY_KEY_COPY,
    GHOSTTY_KEY_CUT,
    GHOSTTY_KEY_PASTE,
    GHOSTTY_KEY_MAX_VALUE = 2147483647,
} GhosttyKey;
__attribute__((visibility("default"))) GhosttyResult ghostty_key_event_new(const GhosttyAllocator *allocator, GhosttyKeyEvent *event);
__attribute__((visibility("default"))) void ghostty_key_event_free(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_action(GhosttyKeyEvent event, GhosttyKeyAction action);
__attribute__((visibility("default"))) GhosttyKeyAction ghostty_key_event_get_action(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_key(GhosttyKeyEvent event, GhosttyKey key);
__attribute__((visibility("default"))) GhosttyKey ghostty_key_event_get_key(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_mods(GhosttyKeyEvent event, GhosttyMods mods);
__attribute__((visibility("default"))) GhosttyMods ghostty_key_event_get_mods(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_consumed_mods(GhosttyKeyEvent event, GhosttyMods consumed_mods);
__attribute__((visibility("default"))) GhosttyMods ghostty_key_event_get_consumed_mods(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_composing(GhosttyKeyEvent event, uint8_t composing);
__attribute__((visibility("default"))) uint8_t ghostty_key_event_get_composing(GhosttyKeyEvent event);
__attribute__((visibility("default"))) void ghostty_key_event_set_utf8(GhosttyKeyEvent event, const char *utf8, size_t len);
__attribute__((visibility("default"))) const char *ghostty_key_event_get_utf8(GhosttyKeyEvent event, size_t *len);
__attribute__((visibility("default"))) void ghostty_key_event_set_unshifted_codepoint(GhosttyKeyEvent event, uint32_t codepoint);
__attribute__((visibility("default"))) uint32_t ghostty_key_event_get_unshifted_codepoint(GhosttyKeyEvent event);
typedef struct GhosttyKeyEncoderImpl *GhosttyKeyEncoder;
typedef uint8_t GhosttyKittyKeyFlags;
typedef enum {
    GHOSTTY_OPTION_AS_ALT_FALSE = 0,
    GHOSTTY_OPTION_AS_ALT_TRUE = 1,
    GHOSTTY_OPTION_AS_ALT_LEFT = 2,
    GHOSTTY_OPTION_AS_ALT_RIGHT = 3,
    GHOSTTY_OPTION_AS_ALT_MAX_VALUE = 2147483647,
} GhosttyOptionAsAlt;
typedef enum {
    GHOSTTY_KEY_ENCODER_OPT_CURSOR_KEY_APPLICATION = 0,
    GHOSTTY_KEY_ENCODER_OPT_KEYPAD_KEY_APPLICATION = 1,
    GHOSTTY_KEY_ENCODER_OPT_IGNORE_KEYPAD_WITH_NUMLOCK = 2,
    GHOSTTY_KEY_ENCODER_OPT_ALT_ESC_PREFIX = 3,
    GHOSTTY_KEY_ENCODER_OPT_MODIFY_OTHER_KEYS_STATE_2 = 4,
    GHOSTTY_KEY_ENCODER_OPT_KITTY_FLAGS = 5,
    GHOSTTY_KEY_ENCODER_OPT_MACOS_OPTION_AS_ALT = 6,
    GHOSTTY_KEY_ENCODER_OPT_BACKARROW_KEY_MODE = 7,
    GHOSTTY_KEY_ENCODER_OPT_MAX_VALUE = 2147483647,
} GhosttyKeyEncoderOption;
__attribute__((visibility("default"))) GhosttyResult ghostty_key_encoder_new(const GhosttyAllocator *allocator, GhosttyKeyEncoder *encoder);
__attribute__((visibility("default"))) void ghostty_key_encoder_free(GhosttyKeyEncoder encoder);
__attribute__((visibility("default"))) void ghostty_key_encoder_setopt(GhosttyKeyEncoder encoder, GhosttyKeyEncoderOption option, const void *value);
__attribute__((visibility("default"))) void ghostty_key_encoder_setopt_from_terminal(GhosttyKeyEncoder encoder, GhosttyTerminal terminal);
__attribute__((visibility("default"))) GhosttyResult ghostty_key_encoder_encode(GhosttyKeyEncoder encoder, GhosttyKeyEvent event, char *out_buf, size_t out_buf_size, size_t *out_len);
typedef struct GhosttyMouseEventImpl *GhosttyMouseEvent;
typedef enum {
  GHOSTTY_MOUSE_ACTION_PRESS = 0,
  GHOSTTY_MOUSE_ACTION_RELEASE = 1,
  GHOSTTY_MOUSE_ACTION_MOTION = 2,
  GHOSTTY_MOUSE_ACTION_MAX_VALUE = 2147483647,
} GhosttyMouseAction;
typedef enum {
  GHOSTTY_MOUSE_BUTTON_UNKNOWN = 0,
  GHOSTTY_MOUSE_BUTTON_LEFT = 1,
  GHOSTTY_MOUSE_BUTTON_RIGHT = 2,
  GHOSTTY_MOUSE_BUTTON_MIDDLE = 3,
  GHOSTTY_MOUSE_BUTTON_FOUR = 4,
  GHOSTTY_MOUSE_BUTTON_FIVE = 5,
  GHOSTTY_MOUSE_BUTTON_SIX = 6,
  GHOSTTY_MOUSE_BUTTON_SEVEN = 7,
  GHOSTTY_MOUSE_BUTTON_EIGHT = 8,
  GHOSTTY_MOUSE_BUTTON_NINE = 9,
  GHOSTTY_MOUSE_BUTTON_TEN = 10,
  GHOSTTY_MOUSE_BUTTON_ELEVEN = 11,
  GHOSTTY_MOUSE_BUTTON_MAX_VALUE = 2147483647,
} GhosttyMouseButton;
typedef struct {
  float x;
  float y;
} GhosttyMousePosition;
__attribute__((visibility("default"))) GhosttyResult ghostty_mouse_event_new(const GhosttyAllocator *allocator,
                                      GhosttyMouseEvent *event);
__attribute__((visibility("default"))) void ghostty_mouse_event_free(GhosttyMouseEvent event);
__attribute__((visibility("default"))) void ghostty_mouse_event_set_action(GhosttyMouseEvent event,
                                    GhosttyMouseAction action);
__attribute__((visibility("default"))) GhosttyMouseAction ghostty_mouse_event_get_action(GhosttyMouseEvent event);
__attribute__((visibility("default"))) void ghostty_mouse_event_set_button(GhosttyMouseEvent event,
                                    GhosttyMouseButton button);
__attribute__((visibility("default"))) void ghostty_mouse_event_clear_button(GhosttyMouseEvent event);
__attribute__((visibility("default"))) uint8_t ghostty_mouse_event_get_button(GhosttyMouseEvent event,
                                    GhosttyMouseButton *out_button);
__attribute__((visibility("default"))) void ghostty_mouse_event_set_mods(GhosttyMouseEvent event,
                                  GhosttyMods mods);
__attribute__((visibility("default"))) GhosttyMods ghostty_mouse_event_get_mods(GhosttyMouseEvent event);
__attribute__((visibility("default"))) void ghostty_mouse_event_set_position(GhosttyMouseEvent event,
                                      GhosttyMousePosition position);
__attribute__((visibility("default"))) GhosttyMousePosition ghostty_mouse_event_get_position(GhosttyMouseEvent event);
typedef struct GhosttyMouseEncoderImpl *GhosttyMouseEncoder;
typedef enum {
  GHOSTTY_MOUSE_TRACKING_NONE = 0,
  GHOSTTY_MOUSE_TRACKING_X10 = 1,
  GHOSTTY_MOUSE_TRACKING_NORMAL = 2,
  GHOSTTY_MOUSE_TRACKING_BUTTON = 3,
  GHOSTTY_MOUSE_TRACKING_ANY = 4,
  GHOSTTY_MOUSE_TRACKING_MAX_VALUE = 2147483647,
} GhosttyMouseTrackingMode;
typedef enum {
  GHOSTTY_MOUSE_FORMAT_X10 = 0,
  GHOSTTY_MOUSE_FORMAT_UTF8 = 1,
  GHOSTTY_MOUSE_FORMAT_SGR = 2,
  GHOSTTY_MOUSE_FORMAT_URXVT = 3,
  GHOSTTY_MOUSE_FORMAT_SGR_PIXELS = 4,
  GHOSTTY_MOUSE_FORMAT_MAX_VALUE = 2147483647,
} GhosttyMouseFormat;
typedef struct {
  size_t size;
  uint32_t screen_width;
  uint32_t screen_height;
  uint32_t cell_width;
  uint32_t cell_height;
  uint32_t padding_top;
  uint32_t padding_bottom;
  uint32_t padding_right;
  uint32_t padding_left;
} GhosttyMouseEncoderSize;
typedef enum {
  GHOSTTY_MOUSE_ENCODER_OPT_EVENT = 0,
  GHOSTTY_MOUSE_ENCODER_OPT_FORMAT = 1,
  GHOSTTY_MOUSE_ENCODER_OPT_SIZE = 2,
  GHOSTTY_MOUSE_ENCODER_OPT_ANY_BUTTON_PRESSED = 3,
  GHOSTTY_MOUSE_ENCODER_OPT_TRACK_LAST_CELL = 4,
  GHOSTTY_MOUSE_ENCODER_OPT_MAX_VALUE = 2147483647,
} GhosttyMouseEncoderOption;
__attribute__((visibility("default"))) GhosttyResult ghostty_mouse_encoder_new(const GhosttyAllocator *allocator,
                                        GhosttyMouseEncoder *encoder);
__attribute__((visibility("default"))) void ghostty_mouse_encoder_free(GhosttyMouseEncoder encoder);
__attribute__((visibility("default"))) void ghostty_mouse_encoder_setopt(GhosttyMouseEncoder encoder,
                                  GhosttyMouseEncoderOption option,
                                  const void *value);
__attribute__((visibility("default"))) void ghostty_mouse_encoder_setopt_from_terminal(GhosttyMouseEncoder encoder,
                                                GhosttyTerminal terminal);
__attribute__((visibility("default"))) void ghostty_mouse_encoder_reset(GhosttyMouseEncoder encoder);
__attribute__((visibility("default"))) GhosttyResult ghostty_mouse_encoder_encode(GhosttyMouseEncoder encoder,
                                           GhosttyMouseEvent event,
                                           char *out_buf,
                                           size_t out_buf_size,
                                           size_t *out_len);
__attribute__((visibility("default"))) uint8_t ghostty_paste_is_safe(const char* data, size_t len);
__attribute__((visibility("default"))) GhosttyResult ghostty_paste_encode(
    char* data,
    size_t data_len,
    uint8_t bracketed,
    char* buf,
    size_t buf_len,
    size_t* out_written);

